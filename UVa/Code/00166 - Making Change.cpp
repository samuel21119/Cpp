/*************************************************************************
  > File Name: 166 - Making Change.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Feb  6 12:32:36 2018
*************************************************************************/

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 100000;
int input[6];
struct coins {
    int p;
    int num;
}a;
int dp1[250], dp2[250];
int coin[] = {1, 2, 4, 10, 20, 40}; // /5
//int coin[] = {5, 10, 20, 50, 100, 200};
int main() {
    bool b;
    double pay;
    int pay2;
    int MAX, ans;
    while (1) {
        b = false;
        MAX = 0;
        for (int i = 0; i < 6; i++) {
            scanf("%d", input + i);
            b |= input[i];
            MAX += coin[i] * input[i];
        }
        if (!b)
            break;
        scanf("%lf", &pay);
        pay *= 100 / 5;
        pay2 = pay;
        for (int i = 0; i <= 200; i++) dp1[i] = dp2[i] = inf;
        ans = inf;
        vector<coins> c;
        for (int i = 0; i < 6; i++) {
            if (input[i] > 2) {
                a.p = coin[i]; a.num = 1;
                c.push_back(a);
                a.p = coin[i] * 2;
                a.num = 2;
                for (int j = 2; j < input[i]; j+=2)
                    c.push_back(a);
                if (!(input[i] & 1)) {
                    a.p = coin[i]; a.num = 1;
                    c.push_back(a);
                }
            }
            else {
                a.p = coin[i];
                a.num = 1;
                for (int j = 0; j < input[i]; j++)
                    c.push_back(a);
            }
        }
        int index = c.size();
        int temp_p, temp_num;
        dp1[0] = dp2[pay2] = 0;
        for (int i = 0; i < index; i++) {
            //printf("%d %d\n", c[i].p, c[i].num);
            temp_p = c[i].p;
            temp_num = c[i].num;
            for (int i = 200; i >= temp_p; i--)
                if (dp1[i - temp_p] < inf)
                    dp1[i] = min(dp1[i], dp1[i - temp_p] + temp_num);
        }
        for (int i = 0; i < 6; i++) {
            temp_p = coin[i];
            for (int j = pay2 + temp_p; j <= MAX && j <= 200; j++)
                dp2[j] = min(dp2[j], dp2[j - temp_p] + 1);
        }
        for (int i = pay2; i <= MAX && i <= 200; i++)
            if (dp1[i] < inf)
                ans = min(ans, dp1[i] + dp2[i]);
        printf("%3d\n", ans);
        //printf("%d %d %d\n", dp1[pay2], dp2[pay2], pay2);
    }
}

/*************************************************************************
  > File Name: 10990 - Lowest Price in Town.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Feb  2 15:27:01 2018
*************************************************************************/

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <sstream>
using namespace std;

double round(double a) {
    int t = a * 100 + 0.5;
    return (double) t / 100;
}
double min(double a, double b) {
    if (a < b)
        return a;
    return b;
}
typedef struct Price {
    int num;
    double p;
}P;
double dp[1201];
P input[22];
int main() {
    double unit, ans;
    int m, k, Mnum, c;
    c = 1;
    while (cin >> unit >> m) {
        input[0].num = 1;
        input[0].p = unit;
        for (int i = 1; i <= m; i++)
            cin >> input[i].num >> input[i].p;
        for (int j = 0; j <= 1200; j++) dp[j] = -1;
        Mnum = 0;
        dp[0] = 0.0;
        for (int i = 0; i <= m; i++)
            for (int j = input[i].num; j <= 1200; j++) {
                if (dp[j - input[i].num] == -1)
                    continue;
                if (dp[j] == -1)
                    dp[j] = dp[j - input[i].num] + input[i].p;
                else
                    dp[j] = min(dp[j], dp[j - input[i].num] + input[i].p);
                Mnum = max(Mnum, input[i].num);
            }
        string s;
        getchar();
        getline(cin, s);
        stringstream ss(s);
        printf("Case %d:\n", c++);
        while (ss >> k) {
            ans = 100000000.0;
            for (int i = k; i <= k + Mnum && i <= 1200; i++)
                if (dp[i] != -1.0)
                    ans = min(ans, dp[i]);
            printf("Buy %d for $%.2lf\n", k, round(ans));
        }
    }
    return 0;
}

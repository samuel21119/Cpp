/*************************************************************************
  > File Name: 00103 - Stacking Boxes.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: 六  4/21 19:23:24 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int k, n;
struct objects {
    int length[12];
    int num;
    bool operator < (objects const &b) const {
        for (int i = 0; i < n; i++)
            if (!(length[i] < b.length[i]))
                return 0;
        return 1;
    }
}input[35];
int dp[35];
int previous[31];
int ans;
void trace(int i) {
    if (previous[i] != -1) trace(previous[i]);
    cout << input[i].num;
    if (--dp[ans])
        cout << ' ';
    else
        cout << '\n';
}
bool cmp(objects a, objects b) {
    for (int i = 0; i < n; i++) {
        if (a.length[i] < b.length[i])
            return 1;
        if (a.length[i] > b.length[i])
            return 0;
    }
    return 0;
}
int main() {
    while (cin >> k >> n) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++)
                cin >> input[i].length[j];
            input[i].num = i + 1;
            sort(input[i].length, input[i].length + n);
        }
        for (int i = 0; i < k; i++) dp[i] = 1;
        sort(input, input + k, cmp);
        for (int i = 0; i < k; i++)
            previous[i] = -1;
        for (int i = 0; i < k; i++)
            for (int j = i + 1; j < k; j++)
                if (input[i] < input[j] && dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                    previous[j] = i;
                }
        ans = 0;
        for (int i = 1; i < k; i++)
            if (dp[ans] < dp[i])
                ans = i;
        cout << dp[ans] << '\n';
        trace(ans);
    }
    return 0;
}

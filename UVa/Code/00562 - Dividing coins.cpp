/*************************************************************************
  > File Name: 00562 - Dividing coins.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jun  4 20:49:48 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bool dp[50000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, sum, s;
    int in[110];
    cin >> m;
    while (m--) {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++)
            cin >> in[i], sum += in[i];
        s = sum >> 1;
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 0; i < n; i++)
            for (int j = s; j >= in[i]; j--)
                dp[j] |= dp[j - in[i]];
        for (int i = s; i >= 0; i--)
            if (dp[i]) {
                s = i << 1;
                break;
            }
        cout << sum - s << '\n';
    }
    return 0;
}

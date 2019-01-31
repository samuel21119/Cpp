/*************************************************************************
  > File Name: 12563 - Jin Ge Jin Qu hao.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jan 27 20:08:34 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, c, t, in, ans, songs;
int dp[10000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    for (int i = 1; i <= c; i++) {
        memset(dp, 0, sizeof(dp));
        ans = songs = 0;
        cin >> n >> t;
        for (int j = 0; j < n; j++) {
            cin >> in;
            for (int k = t; k > in; k--)
                if (dp[k - in] > 0)
                    dp[k] = max(dp[k], dp[k - in] + 1);
            dp[in] = max(dp[in], 1);
        }
        if (dp[t])
            ans = t, songs = dp[t];
        for (int j = t - 1; j; j--)
            if (dp[j]) {
                if (songs <= dp[j])
                    ans = j + 678, songs = dp[j] + 1;
                else if (songs == dp[j] + 1)
                    ans = max(ans, j + 678);
            }
        if (!songs)
            songs = 1, ans = 678;
        cout << "Case " << i << ": " << songs << ' ' << ans << '\n';
    }
    return 0;
}

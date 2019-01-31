/*************************************************************************
  > File Name: 01427 - Parade.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Dec 11 09:21:54 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll dp[2][10010];
ll love[110][10010];
ll len[110][10010], k;
int dq[10010], l, r;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m >> k && (n || m || k)) {
        n++;
        for (int i = n; i; i--)
            for (int j = 1; j <= m; j++) {
                cin >> love[i][j];
                love[i][j] += love[i][j - 1];
            }
        for (int i = n; i; i--)
            for (int j = 1; j <= m; j++) {
                cin >> len[i][j];
                len[i][j] += len[i][j - 1];
            }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            int now = i & 1;
            int prev = !now;
            l = r = 0;
            for (int j = 0; j <= m; j++) {
                while (l != r && len[i][j] - len[i][dq[l]] > k)
                    l++;
                while (l != r && dp[prev][j] - love[i][j] >= dp[prev][dq[r - 1]] - love[i][dq[r - 1]])
                    r--;
                dq[r++] = j;
                dp[now][j] = dp[prev][dq[l]] - love[i][dq[l]] + love[i][j];
            }
            l = r = 0;
            for (int j = m; j >= 0; j--) {
                while (l != r && len[i][dq[l]] - len[i][j] > k)
                    l++;
                while (l != r && dp[prev][j] + love[i][j] >= dp[prev][dq[r - 1]] + love[i][dq[r - 1]])
                    r--;
                dq[r++] = j;
                dp[now][j] = max(dp[now][j], dp[prev][dq[l]] + love[i][dq[l]] - love[i][j]);
            }
        }
        ll ans = 0;
        for (int i = 0; i <= m; i++)
            ans = max(ans, dp[n & 1][i]);
        cout << ans << '\n';
    }
    return 0;
}

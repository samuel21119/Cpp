/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 21 06:42:14 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int dp[40][70], ans[2][70];
int n, m, mod;
int in[75][75];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> mod;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> in[i][j];
    for (int i = 0; i < n; i++) {
        int now = i & 1;
        int pre = !now;

        for (int j = 0; j <= m / 2; j++)
            memset(dp[j], 0, sizeof(dp[0]));
        for (int j = 0; j < m; j++) {
            for (int a = m / 2 - 1; a >= 0; a--)
                for (int b = 0; b < mod; b++) {
                    if (dp[a][b] % mod == b)
                        dp[a + 1][(b + in[i][j]) % mod] = max(dp[a + 1][(b + in[i][j]) % mod], dp[a][b] + in[i][j]);
                }
        }

        for (int j = 0; j < mod; j++) {
            int mx = 0;
            for (int k = 0; k <= m / 2; k++) {
                mx = max(mx, dp[k][j]);
            }
            for (int k = 0; k < mod; k++)
                if (ans[pre][k] % mod == k)
                    ans[now][(k + mx) % mod] = max(ans[now][(k + mx) % mod], ans[pre][k] + mx);
        }
        cout << "i: " << i << '\n';
        for (int j = 0; j <= m / 2; j++) {
            for (int k = 0; k < mod; k++) {
                //cout << dp[j][k] << ' ';
                cout << ans[now][k] << ' ';
            }
            cout<< '\n';
            break;
        }
    }
    cout << ans[!(n & 1)][0] << '\n';
    return 0;
}

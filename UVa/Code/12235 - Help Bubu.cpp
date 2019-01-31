/*************************************************************************
  > File Name: 12235 - Help Bubu.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep 30 20:55:26 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;
int in[110], two[256];
bool cnt[9];
int n, m, ans, tmp, now, pre, len = 1 << 8;
int dp[2][110][1 << 8][9];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 0;
    for (int i = 0; i < len; i++) {
        int j = i;
        while (j)
            two[i] += j & 1, j >>= 1;
    }
    while (cin >> n >> m && n + m) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cin >> in[i];
            in[i] -= 24;
            cnt[in[i]] = 1;
        }
        tmp = 0;
        ans = inf;
        for (int i = 1; i < 9; i++)
            tmp += cnt[i];
        memset(dp, 127, sizeof(dp));
        dp[0][0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            now = i & 1;
            pre = !now;
            memset(dp[now], 127, sizeof(dp[now]));
            for (int j = 0; j <= min(i, m); j++)
                for (int s = 0; s < len; s++)
                    for (int k = 0; k <= 8; k++)
                        if (in[i] == k)
                            dp[now][j][s][k] = min(dp[now][j][s][k], dp[pre][j][s][k]);
                        else {
                            dp[now][j][s | (1 << (in[i] - 1))][in[i]] = min(dp[now][j][s | (1 << (in[i] - 1))][in[i]], dp[pre][j][s][k] + 1);
                            dp[now][j + 1][s][k] = min(dp[now][j + 1][s][k], dp[pre][j][s][k]);
                        }
        }
        for (int j = 0; j <= m; j++)
            for (int s = 0; s < len; s++)
                for (int k = 0; k <= 8; k++)
                    ans = min(ans, dp[now][j][s][k] + tmp - two[s]);
        cout << "Case " << ++t << ": " << ans << "\n\n";
    }
    return 0;
}

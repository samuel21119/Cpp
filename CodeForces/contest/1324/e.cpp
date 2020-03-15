/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 12 21:52:19 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int dp[2][2010];
int in[2010];
int n, h, l, r;
void update(int &a, int b) {
    a = max(a, b);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp[0], -1, sizeof(dp[0]));
    dp[0][0] = 0;
    cin >> n >> h >> l >> r;
    for (int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        int now = i & 1;
        int pre = !now;
        memset(dp[now], -1, sizeof(dp[now]));
        for (int j = 0; j < h; j++) {
            if (dp[pre][j] == -1)
                continue;
            for (int k = -1; k <= 0; k++) {
                int t = j + in + k; t %= h;
                if (l <= t && t <= r)
                    update(dp[now][t], dp[pre][j] + 1);
                else
                    update(dp[now][t], dp[pre][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
        update(ans, dp[n & 1][i]);
    cout << ans << '\n';
    return 0;
}

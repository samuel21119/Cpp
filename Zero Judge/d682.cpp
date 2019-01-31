/*************************************************************************
  > File Name: d682.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Sep 29 21:07:20 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int m, n, p, ans, cost, attack;
int dp[2][10010];
bool now;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> p;
    for (int i = 0; i < n; i++) {
        now = i & 1;
        memcpy(dp[now], dp[!now], sizeof(dp[now]));
        for (int j = 0; j < p; j++) {
            cin >> cost >> attack;
            for (int k = m; k >= cost; k--)
                dp[now][k] = max(dp[now][k], dp[!now][k - cost] + attack);
        }
    }
    m++;
    while (m--)
        ans = max(ans, dp[!(n & 1)][m]);
    cout << ans << '\n';
    return 0;
}

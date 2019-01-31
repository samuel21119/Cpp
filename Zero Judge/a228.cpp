/*************************************************************************
  > File Name: a228.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jul 27 17:28:13 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1000000007;
int n, m;
bool tree[12][12];
ll dp[13][13][1 << 13];
ll sol() {
    memset(dp, 0, sizeof(dp));
    dp[0][m][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s < (1 << m); s++)
            dp[i][0][s << 1] = dp[i - 1][m][s];
        for (int j = 1; j <= m; j++) {
            for (int s = 0; s < (1 << (m + 1)); s++) {
                int a = 1 << (j - 1);
                int b = 1 << j;
                if (tree[i][j]) {
                    if ((a & s) && (b & s))
                        dp[i][j][s] = dp[i][j - 1][s - a - b];
                    else if ((a & s) || (b & s))
                        dp[i][j][s] = (dp[i][j - 1][s] + dp[i][j - 1][s ^ a ^ b]) % mod;
                    else
                        dp[i][j][s] = dp[i][j - 1][s + a + b];
                }else {
                    if ((s & a) || (s & b))
                        dp[i][j][s] = 0;
                    else
                        dp[i][j][s] = dp[i][j - 1][s];
                }
            }
        }
    }
    return dp[n][m][0] % mod;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> tree[i][j];
        cout << "Case " << i << ": " << sol() << '\n';
    }
    return 0;
}

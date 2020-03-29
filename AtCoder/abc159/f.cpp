/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Mar 22 21:56:59 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[3010][3010];
const ll mod = 998244353;
int n, s;
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        memcpy(dp[i], dp[i - 1], sizeof(dp[0]));
        dp[i][in] = (dp[i][in] + i) % mod;
        for (int j = 0; j + in <= s; j++)
            dp[i][j + in] = (dp[i][j + in] + dp[i - 1][j]) % mod;
        ans = (ans + dp[i][s]) % mod;
    }
    cout << ans << '\n';
    return 0;
}

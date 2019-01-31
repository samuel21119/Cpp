/*************************************************************************
  > File Name: D.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon May 28 22:08:25 2018
*************************************************************************/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll input[51];
ll dp[56];
int n, k;
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> input[i];
    for (int i = 2; i <= n; i++) input[i] += input[i - 1];
    input[0] = 0;
    ans = 0;
    for (int i = 55; i >= 0; i--) {
        ans |= 1ll << i;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j <= n; j++) 
                if ((input[j] - input[i] & ans) == ans)
                    dp[j] |= dp[i] << 1;
        if (!((dp[n] >> k) & 1)) ans ^= 1ll << i;
    }
    cout << ans << '\n';
    return 0;
}

/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 17 19:15:18 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int h, n, mx;
long long dp[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> n;
    for (int i = 1; i <= h + 10000; i++)
        dp[i] = 1LL << 60;
    for (int i = 0; i < n; i++) {
        int atk, mana;
        cin >> atk >> mana;
        mx = max(mx, atk);
        for (int j = 0; j < h; j++)
            dp[j + atk] = min(dp[j + atk], dp[j] + mana);
    }
    long long ans = 1LL << 60;
    for (int i = 0; i < mx; i++) {
        ans = min(ans, dp[i + h]);
    }
    cout << ans << '\n';
    return 0;
}

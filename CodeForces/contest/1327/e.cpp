/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Mar 23 23:39:24 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
ll n;
ll ten[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ten[0] = 1;
    for (int i = 1; i <= n; i++)
        ten[i] = (ten[i - 1] * 10) % mod;
    for (int i = 1; i < n; i++) {
        ll m = n - i - 1;
        ll ans = 0;
        ans = (ans + 180LL * ten[n - i - 1]) % mod;
        if (m > 0)
            ans = (ans + 810LL * m % mod * ten[m - 1]) % mod;
        cout << ans << ' ';
    }
    cout << 10;
    return 0;
}

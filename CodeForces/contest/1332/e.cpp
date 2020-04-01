/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 31 23:09:06 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
ll p(ll a, ll cnt) {
    if (cnt == 0)
        return 1;
    if (cnt == 1)
        return a % mod;
    ll t = p(a, cnt / 2) % mod;
    return t * t % mod * (cnt & 1 ? a : 1) % mod;
}
ll n, m, l, r;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l >> r;
    ll nm = n * m;
    ll d = r - l + 1;
    ll ans;
    if (nm & 1)
        ans = p(d, nm);
    else
        ans = (p(d, nm) + (d % 2)) % mod * p(2, mod - 2) % mod;
    cout << ans << '\n';
    return 0;
}

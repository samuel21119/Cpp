/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Dec 28 22:56:59 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll in;
        cin >> in;
        in *= 2;
        ll t = gcd(360, in);
        ll m = 360 / t;
        in /= t;
        ll ans = 1LL << 60;
        for (ll i = 1; i < 360; i++) {
            if ((m * i) % in)
                continue;
            if (m * i / in - 2 < i)
                continue;
            ans = min(ans, m * i / in);
        }
        cout << ans << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat May 16 21:54:08 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll l, r;
ll solve(ll &l, ll &r, ll cnt) {
    ll L = 0;
    ll R = 1e9 * 2;
    ll a, b;
    while (L + 1 < R) {
        ll m = (L + R) / 2;
        a = (m + 1) / 2;
        b = m / 2;
        a = (2 * cnt + 2 * a - 2) * a / 2;
        b = (2 * cnt + 2 * b) * b / 2;
        if (l >= a && r >= b)
            L = m;
        else
            R = m;
    }
    ll m = L;
    a = (m + 1) / 2;
    b = m / 2;
    a = (2 * cnt + 2 * a - 2) * a / 2;
    b = (2 * cnt + 2 * b) * b / 2;
    l -= a, r -= b;
    return L;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int a = 1; a <= t; a++) {
        cin >> l >> r;
        ll x = abs(l - r), ans;
        double tmp = (sqrt(1 + 8 * x) - 1) / 2;
        x = tmp;
        if (l >= r)
            l -= (x + 1) * x / 2;
        else
            r -= (x + 1) * x / 2;
        //cout << x << ' '<<  l << ' ' << r << endl;
        if (l >= r)
            ans = solve(l, r, x + 1);
        else
            ans = solve(r, l, x + 1);
        cout << "Case #" << a << ": " << ans + x << ' ' << l << ' ' << r << '\n';
    }
    return 0;
}

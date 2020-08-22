/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 21 22:42:43 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll x[3];
ll y[3];
int t2[] = {1, 2, 0};
int t1[] = {1, 0, 2};
ll re(ll a, ll b) {
    if (a == b)
        return 0;
    if (a > b)
        return a * b;
    return -a * b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++)
            cin >> x[i];
        for (int i = 0; i < 3; i++)
            cin >> y[i];
        ll ans = 0;
        for (int i = 0; i < 3 && x[2] > 0; i++) {
            ll mn = min(x[2], y[t2[i]]);
            ans += mn * re(2, t2[i]);
            x[2] -= mn, y[t2[i]] -= mn;
        }
        for (int i = 0; i < 3 && x[1] > 0; i++) {
            ll mn = min(x[1], y[t1[i]]);
            ans += mn * re(1, t1[i]);
            x[1] -= mn, y[t1[i]] -= mn;
        }
        cout << ans << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed May  6 22:40:25 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t;
typedef long long ll;
ll n;
vector<ll> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    ll t = 2;
    ll now = 5;
    v.emplace_back(0);
    while (t <= 1e9 * 2) {
        v.emplace_back(t);
        t += now;
        now += 3;
    }
    while (T--) {
        cin >> n;
        int ans = 0;
        while (1) {
            auto x = upper_bound(v.begin(), v.end(), n);
            if (x == v.begin())
                break;
            ll a = *(--x);
            if (a == 0)
                break;
            n -= a;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}

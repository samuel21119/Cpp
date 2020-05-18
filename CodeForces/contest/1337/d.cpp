/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Apr 16 00:15:58 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n[3];
vector<ll> x[3];
inline ll two(ll a, ll b) {
    return (a - b) * (a - b);
}
inline ll f(ll a, ll b, int next) {
    ll m = (a + b) / 2;
    int t = lower_bound(x[next].begin(), x[next].end(), m) - x[next].begin();
    if (t == (int)x[next].size())
        t--;
    ll re1 = two(a, b) + two(b, x[next][t]) + two(a, x[next][t]);
    //cout << t << ' ' << a << ' ' << b << ' ' << x[next][t] << '\n';
    if (t > 0) {
        t--;
        ll re2 = two(a, b) + two(b, x[next][t]) + two(a, x[next][t]);
        re1 = min(re1, re2);
    }
    return re1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++)
            cin >> n[i];
        for (int i = 0; i < 3; i++) {
            x[i].resize(n[i]);
            for (int j = 0; j < n[i]; j++)
                cin >> x[i][j];
            sort(x[i].begin(), x[i].end());
            x[i].resize(unique(x[i].begin(), x[i].end()) - x[i].begin());
        }
        ll ans = 1LL << 62;
        for (int i = 0; i < 3; i++) {
            int next = (i + 1) % 3;
            int next2 = (i + 2) % 3;
            ll a;
            for (int j = 0; j < n[i]; j++) {
                a = x[i][j];
                int t1 = lower_bound(x[next].begin(), x[next].end(), a) - x[next].begin();
                if (t1 == n[next])
                    t1--;
                ll re1 = f(a, x[next][t1], next2);
                if (t1 > 0)
                    re1 = min(re1, f(a, x[next][t1 - 1], next2));
                ans = min(ans, re1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

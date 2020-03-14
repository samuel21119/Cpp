/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar 14 23:06:58 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[70];
ll sum = 0;
ll u, v, v2;
bool anss;
void add(ll i, int c) {
    ans[c]++;
    if (sum + i > v2) {
        anss = 1;
        return;
    }
    sum += i;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> u >> v;
    if ((u % 2 != v % 2) || u > v) {
        cout << -1 << '\n';
        return 0;
    }
    if (v == 0) {
        cout << (u == 0 ? 0 : -1) << '\n';
        return 0;
    }
    v2 = v;
    for (ll i = 1, j = 0; i <= v; i *= 2, j++) {
        ll uu = u >> j;
        ll vv = v >> j;
        uu &= 1;
        vv &= 1;
        if (uu == vv) {
            if (uu)
                add(i, j);
        }else if (uu != vv) {
            if (uu) {
                add(i, j);
                v -= i << 1;
                if (v < 0)
                    anss = 1;
            }
            add(i / 2, j - 1);
            add(i / 2, j - 1);
        }
    }
    if ((sum != v2) || anss)
        cout << -1;
    else {
        vector<ll> v;
        while (1) {
            int mn = 1e9;
            ll s = 0;
            bool con = 0;
            int mx = 0;
            for (ll i = 0, j = 1; j <= v2; j <<= 1, i++) {
                if (ans[i] > 0) {
                    mn = min(mn, ans[i]);
                    s += j;
                    con = 1;
                    mx = i;
                }
            }
            for (ll i = 0; i <= mx; i++) {
                if (ans[i] > 0) {
                    ans[i] -= mn;
                }
            }
            if (!con)
                break;
            while (mn--)
                v.emplace_back(s);
        }
        cout << v.size() << '\n';
        for (ll i : v)
            cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

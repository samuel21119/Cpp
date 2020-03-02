/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan 20 10:15:19 2020
*************************************************************************/

#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef long long ll;

const ll m = 1e16*2+1;
ll x, y, t, xx, yy;
inline ll cnt_dist(ll a, ll b) {
    return abs(a - x) + abs(b - y);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << m;
    ll x0, y0, ax, ay, bx, by;
    vector<pair<ll, ll>> node;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> x >> y >> t;
    xx = x, yy = y;
    ll xp = x0, yp = y0;
    node.push_back({x0, y0});
    for (int i = 0; i < 64; i++) {
        if (xp > m || yp > m)
            break;
        ll nx = xp * ax + bx;
        ll ny = yp * ay + by;
        xp = nx;
        yp = ny;
        //cout << nx << ' ' << ny << '\n';
        if (cnt_dist(nx, ny) <= t)
            node.push_back({nx, ny});
    }
    int start = -1;
    ll dist = 1LL << 62;
    for (unsigned i = 0; i < node.size(); i++) {
        if (cnt_dist(node[i].F, node[i].S) < dist) {
            dist = cnt_dist(node[i].F, node[i].S);
            start = i;
        }
    }
    int ans = 0;
    ll tt = t;
    for (int i = start; i >= 0 && t > 0; i--) {
        ll nowX = node[i].F;
        ll nowY = node[i].S;
        ll run = cnt_dist(nowX, nowY);
        if (t < run) break;
        t -= run;
        ans++;
        x = nowX;
        y = nowY;
    }
    for (int i = start + 1; i < node.size() && t > 0; i++) {
        ll nowX = node[i].F;
        ll nowY = node[i].S;
        ll run = cnt_dist(nowX, nowY);
        if (t < run) break;
        t -= run;
        ans++;
        x = nowX;
        y = nowY;
    }
    int ans2 = 0;
    x = xx, y = yy;
    for (int i = start + 1; i >= 0 && t > 0; i--) {
        ll nowX = node[i].F;
        ll nowY = node[i].S;
        ll run = cnt_dist(nowX, nowY);
        if (tt < run) break;
        tt -= run;
        ans2++;
        x = nowX;
        y = nowY;
    }
    cout << max(ans, ans2) << '\n';
    return 0;
}

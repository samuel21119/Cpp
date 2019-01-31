/*************************************************************************
  > File Name: 10397 - Connect the Campus.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 13 13:45:40 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 751;
int n, m, cnt;
double ans;
struct Disjoint {
    int p[maxn];
    void init() {
        for (int i = 0; i < maxn; i++)
            p[i] = i;
    }
    int parent(int i) {
        while (i != p[i])
            i = p[i];
        return i;
    }
    void connect(int a, int b) {
        p[parent(b)] = parent(a);
    }
    bool same(int a, int b) {
        return(parent(a) == parent(b));
    }
};
struct xy {
    int x, y;
    xy(){}
    xy(int x, int y) : x(x), y(y){}
}point[752];
struct l {
    int a, b;
    double len;
    l(){}
    l(int a, int b, double len) : a(a), b(b), len(len){}
    bool operator< (l const &b) const {
        return len < b.len;
    }
}line[562510];
double calc(int a, int b) {
    int xx = point[a].x - point[b].x;
    int yy = point[a].y - point[b].y;
    xx *= xx;
    yy *= yy;
    return sqrt(xx + yy);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed  <<  setprecision(2);
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++)
            cin >> point[i].x >> point[i].y;
        Disjoint d;
        d.init();
        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;
            d.connect(a, b);
        }
        ans = cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                line[cnt++] = {i, j, calc(i, j)};
        sort(line, line + cnt);
        for (int i = 0; i < cnt; i++) {
            int a = line[i].a;
            int b = line[i].b;
            if (d.same(a, b))
                continue;
            d.connect(a, b);
            ans += line[i].len;
        }
        cout << ans << '\n';
    }
    return 0;
}

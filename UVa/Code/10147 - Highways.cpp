/*************************************************************************
  > File Name: 10147 - Highways.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jul  1 15:25:31 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m, roads;
bool flag;
double road[755][755];
struct DOT {
    int x, y;
}dot[755];
struct edge {
    int a, b;
    double len;
    bool operator < (edge const &b) const {
        return len < b.len;
    }
}e[562600];
int parent[755];

int pow(int a) {
    return a * a;
}
int findP(int target) {
    if (target == parent[target])
        return target;
    return parent[target] = findP(parent[target]);
}
void solve() {
    for (int i = 0; i < roads; i++) {
        edge cur = e[i];
        int pa = findP(cur.a);
        int pb = findP(cur.b);
        if (pa == pb)
            continue;
        parent[pb] = pa;
        if (cur.len > 0) {
            cout << cur.a + 1 << ' ' << cur.b + 1 << '\n';
            flag = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, a;
    cin >> t;
    while (t--) {
        cin >> n;
        roads = 0;
        for (int i = 0; i < n; i++)
            cin >> dot[i].x >> dot[i].y;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                road[i][j] = road[j][i] = sqrt( pow(dot[i].x - dot[j].x) + pow(dot[i].y - dot[j].y) );
        cin >> a;
        while (a--) {
            int x, y;
            cin >> x >> y; x--, y--;
            road[x][y] = road[y][x] = 0;
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                e[roads].a = i;
                e[roads].b = j;
                e[roads++].len = road[i][j];
            }
        sort(e, e + roads);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        flag = 1;
        solve();
        if (flag)
            cout << "No new highways need\n";
        if (t)
            cout << '\n';
    }
    return 0;
}

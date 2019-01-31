/*************************************************************************
  > File Name: 10369 - Arctic Network.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jul  2 10:19:18 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct l {
    int a, b;
    double len;
    l(int _a, int _b, double _l) : a(_a), b(_b), len(_l) {}
    l() {}
    bool operator < (l const B) const {
        return len < B.len;
    }
}line[125010];
struct Point {
    int x, y;
}point[501];
int s, p, cnt;
int parent[501];
int pow(int a) {
    return a * a;
}
int findp(int target) {
    if (target == parent[target])
        return target;
    return parent[target] = findp(parent[target]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    int c;
    cin >> c;
    while (c--) {
        cin >> s >> p;
        cnt = 0;
        double ans = 0.0;
        for (int i = 0; i < p; i++) {
            cin >> point[i].x >> point[i].y;
            parent[i] = i;
        }
        for (int i = 0; i < p; i++)
            for (int j = i + 1; j < p; j++)
                line[cnt++] = {i, j, sqrt(pow(point[i].x - point[j].x) + pow(point[i].y - point[j].y))};
        sort(line, line + cnt);
        s = p - s;
        for (int i = 0; i < cnt; i++) {
            l cur = line[i];
            int pa = findp(cur.a);
            int pb = findp(cur.b);
            if (pa == pb)
                continue;
            parent[pb] = pa;
            if (!(--s)) {
                ans = cur.len;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

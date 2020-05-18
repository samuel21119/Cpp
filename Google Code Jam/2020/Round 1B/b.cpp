/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Apr 20 01:13:25 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int full = 1e9;
const int half = 1e9 / 2;
bool cont;
int f(int x, int y, int dx, int dy) {
    int l, r;
    if (dy == 0)
        l = x, r = full * dx;
    else
        l = y, r = full * dy;
    while (dx + dy > 0 ? l < r - 1 : l > r + 1) {
        int m = (l + r) / 2;
        if (dx)
            cout << m << ' ' << y << endl;
        else
            cout << x << ' ' << m << endl;
        string s;
        cin >> s;
        if (s == "HIT") {
            l = m;
        }else if (s == "CENTER") {
            cont = 1;
            return 0;
        }else {
            r = m;
        }
    }
    return l;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    int a, b;
    cin >> a >> b;
    for (int t = 1; t <= T; t++) {
        int x, y;
        bool br = 1;
        cont = 0;
        for (int i = -1; i <= 1 && br; i++)
            for (int j = -1; j <= 1 && br; j++) {
                cout << half * i << ' ' << half * j << endl;
                string s;
                cin >> s;
                if (s == "HIT") {
                    x = half * i;
                    y = half * j;
                    br = 0;
                }else if (s == "CENTER")
                    br = 0, cont = 1;
            }
        if (cont)
            continue;
        int ux, dx, uy, dy;
        ux = f(x, y, 1, 0);
        if (cont)
            continue;
        dx = f(x, y, -1, 0);
        if (cont)
            continue;
        uy = f(x, y, 0, 1);
        if (cont)
            continue;
        dy = f(x, y, 0, -1);
        if (cont)
            continue;
        cout << (ux + dx) / 2 << ' ' << (uy + dy) / 2 << endl;
        string s;
        cin >> s;
    }
    return 0;
}

/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Aug 13 06:43:49 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> sx >> sy;

    cout << sx << ' ' << sy << '\n';
    for (int i = n; i; i--) {
        if (i == sx)
            continue;
        cout << i << ' ' << sy << '\n';
    }
    bool cnt = 1;
    for (int j = 1; j <= m; j++) {
        if (j == sy)
            continue;
        for (int i = 1; i <= n; i++) {
            cout << (cnt ? i : n - i + 1) << ' ' << j << '\n';
        }
        cnt ^= 1;
    }
    return 0;
}

/*************************************************************************
  > File Name: 10048 - Audiophobia.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 13 14:51:09 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int line[1001][1001];
int inf = 1 << 30;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, s, q, t;
    t = 0;
    while (cin >> c >> s >> q && c) {
        for (int i = 0; i <= c; i++)
            for (int j = 0; j <= c; j++)
                line[i][j] = inf;
        while (s--) {
            int a, b, c;
            cin >> a >> b >> c;
            line[a][b] = line[b][a] = c;
        }
        for (int k = 1; k <= c; k++)
            for (int i = 1; i <= c; i++)
                for (int j = 1; j <= c; j++) {
                    line[i][j] = min(line[i][j], max(line[i][k], line[k][j]));
                    line[j][i] = line[i][j];
                }
        if (t)
            cout << '\n';
        cout << "Case #" << ++t << '\n';
        while (q--) {
            int a, b;
            cin >> a >> b;
            if (line[a][b] == inf) {
                cout << "no path\n";
                continue;
            }
            cout << line[a][b] << '\n';
        }
    }
    return 0;
}

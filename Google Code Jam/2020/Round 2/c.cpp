/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat May 16 23:51:01 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t;
int n;
pair<int, int> x[10];
int per[10];

void get_xy(int i, int &X, int &Y) {
    X = x[i].first;
    Y = x[i].second;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int a = 1; a <= t; a++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            x[i] = {a, b};
            per[i] = i;
        }
        cout << "Case #" << a << ": ";
        int ans = min(4, n);
        do {
            double dir = 0;
            int A = 0;
            int B;
            for (int i = 1; i + 1 < n; i += 2) {
                int a = per[i];
                int b = per[i + 1];
                int x1, x2, y1, y2;
                get_xy(a, x1, y1);
                get_xy(b, x2, y2);
                double dx = x1 - x2;
                double dy = y1 - y2;
                double m;
                int AA = dy >= 0;
                int BB = dx >= 0;
                if (dx == 0)
                    m = dy > 0 ? 1e9 * 3 : -1e9 * 3;
                else
                    m = dy / dx;
                
                if (i == 1) {
                    dir = m;
                    A = AA;
                    B = BB;
                }
                else {
                    if (dir == m && AA == A && BB == B)
                        ans = max(ans, i + 2);
                    else {
                        ans = max(ans, i + 1);
                        break;
                    }
                }
            }       
        }while (next_permutation(per, per + n));
        cout << ans << '\n';
    }
    return 0;
}

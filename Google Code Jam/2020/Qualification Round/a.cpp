/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Apr  4 09:59:39 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k, r, c;
int in[110][110];
bool use[110];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        k = r = c = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> in[i][j];
        for (int i = 0; i < n; i++)
            k += in[i][i];
        for (int i = 0; i < n; i++) {
            memset(use, 0, sizeof(use));
            bool add = 1;
            for (int j = 0; j < n && add; j++) {
                add &= !use[in[i][j]];
                use[in[i][j]] = 1;
            }
            r += !add;
        }
        for (int i = 0; i < n; i++) {
            memset(use, 0, sizeof(use));
            bool add = 1;
            for (int j = 0; j < n && add; j++) {
                add &= !use[in[j][i]];
                use[in[j][i]] = 1;
            }
            c += !add;
        }
        cout << "Case #" << t << ": " << k << ' ' << r << ' ' << c << '\n';
    }
    return 0;
}

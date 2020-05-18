/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Apr  8 22:25:24 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool a = (n * m) % 2;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ((i + j) % 2 ? 'B' : 'W');
            cout << '\n';
        }
        for (int j = 1; j < m - 1; j++) {
            cout << ((n + j + 1) % 2 ? 'B' : 'W');
        }
        if (a)
            for (int j = m - 1; j <= m; j++)
                cout << ((n + j + 1) % 2 ? 'B' : 'W');
        else
            cout << "BB";
        cout << '\n';
    }
    return 0;
}

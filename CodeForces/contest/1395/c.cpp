/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Aug 13 06:52:57 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200], b[200];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < 512; i++) {
        bool can = 1;
        for (int x = 0; x < n; x++) {
            bool cnt = 0;
            for (int y = 0; y < m; y++)
                if (((a[x] & b[y]) | i) == i) {
                    cnt = 1;
                    break;
                }
            can &= cnt;
            if (!cnt)
                break;
        }
        if (can) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}

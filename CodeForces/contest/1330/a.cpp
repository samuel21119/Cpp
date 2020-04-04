/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Apr  3 22:32:11 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int in[100];
int u[210];
int n, x;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        memset(u, 0, sizeof(u));
        for (int i = 0; i < n; i++) {
            cin >> in[i];
            u[in[i]] = 1;
        }
        int cnt = 0;
        for (int i = 1; i < 210; i++) {
            if (u[i]) {
                cnt = i;
                continue;
            }
            x--;
            u[i] = 1;
            if (x < 0)
                break;
            cnt = i;
        }
        cout << cnt << '\n';
    }
    return 0;
}

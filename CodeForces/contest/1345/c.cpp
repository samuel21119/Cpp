/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed May  6 22:58:34 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool vis[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 1;
        cin >> n;
        for (int i = 0; i < n; i++)
            vis[i] = 0;
        for (int i = 0; i < n; i++) {
            int x, t;
            cin >> x;
            t = ((i + x) % n + n) % n;
            if (vis[t])
                ans = 0;
            vis[t] = 1;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Mar  6 09:11:57 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[5010];
bool solve() {
    int mx = 1;
    for (int i = 1; i <= n; i++) {
        int add = (i - 1) / 2;
        if (m >= add && m > 0) {
            ans[i] = i;
            m -= add;
            mx = max(mx, i + 1);
        }else if (m == 0) {
            int cnt = 0;
            for (int j = n; j >= i; j--)
                ans[j] = 1e9 - (cnt++) * mx;
        }else {
            int x = (i - 2) - 2 * m;
            ans[i] = x + i;
            mx = max(mx, x + i + 1);
            m = 0;
        }
    }
    if (m > 0)
        return 0;
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx += (n - 1) / 2;
    if (mx < m || !solve()) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}

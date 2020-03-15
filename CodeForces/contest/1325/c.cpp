/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar 14 22:54:30 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v[100010];
pair<int, int> link[100000];
int ans[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(ans, -1, sizeof(ans));
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        link[i] = {a, b};
        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }
    bool ok = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() >= 3) {
            for (int j = 0; j < 3; j++) {
                ans[v[i][j].second] = j;
            }
            ok = 1;
            break;
        }
    }
    if (ok) {
        int cnt = 3;
        for (int i = 0; i < n - 1; i++) {
            cout << (ans[i] != -1 ? ans[i] : cnt++) << '\n';
        }
    }else {
        for (int i = 0; i < n - 1; i++)
            cout << i << '\n';
    }
    return 0;
}

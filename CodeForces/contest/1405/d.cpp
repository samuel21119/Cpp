/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep 10 14:50:41 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, a, b, da, db;
vector<int> graph[100010];
int deep[100010], mxdia;

int dfs(int now, int pa, int dp) {
    int mx1, mx2;
    mx1 = mx2 = 0;
    deep[now] = dp;
    for (int i : graph[now]) {
        if (i == pa)
            continue;
        int t = dfs(i, now, dp + 1) + 1;
        if (t >= mx1) {
            mx2 = mx1;
            mx1 = t;
        }else if (t > mx2)
            mx2 = t;
    }
    mxdia = max(mxdia, mx1 + mx2);
    return mx1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++)
            graph[i].clear();
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        mxdia = 0;
        dfs(a, 0, 0);
        if (da * 2 < db && deep[b] > da && mxdia > da * 2)
            cout << "Bob";
        else
            cout << "Alice";
        cout << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: 10305 - Ordering Tasks.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Dec 13 15:22:53 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int dp[maxn], n, m, a, b;
vector<int> ans[maxn], link[maxn];
int dfs(int x) {
    if (dp[x])
        return dp[x];
    for (int &i : link[x])
        dp[x] = max(dp[x], 1 + dfs(i));
    return dp[x];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m && (n + m)) {
        for (int i = 0; i <= n; i++) {
            ans[i].clear();
            link[i].clear();
        }
        while (m--) {
            cin >> a >> b;
            link[a].emplace_back(b);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            ans[dfs(i)].emplace_back(i);
        for (int i = n - 1; i >= 0; i--)
            for (int &j : ans[i])
                cout << j << ' ';
        cout << '\n';
    }
    return 0;
}

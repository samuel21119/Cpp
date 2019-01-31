/*************************************************************************
  > File Name: 我愛海洋.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri May 18 22:33:28 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
vector<int> line[100002];
int d[100002];
int dp[100002];
int n, m;

int dfs(int x) {
    if (dp[x] != -1)
        return dp[x];
    int len = line[x].size();
    int next;
    dp[x] = 0;
    for (int i = 0; i < len; i++) {
        next = line[x][i];
        dfs(next);
        dp[x] = max(dp[x], dp[next] + 1);
    }
    return dp[x];
}

int main() {
    cin >> n >> m;
    int tmp, tmp2;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        d[i] = tmp;
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp >> tmp2;
        if (tmp == tmp2)
            continue;
        if (d[tmp] < d[tmp2])
            line[tmp].push_back(tmp2);
        else
            line[tmp2].push_back(tmp);
    }
    for (int i = 1; i <= n; i++)
        dp[i] = -1;
    int ans = 0;

    for (int i = 1; i <= n; i++)
        ans = max(ans, dfs(i));
    cout << ans << '\n';
    return 0;
}

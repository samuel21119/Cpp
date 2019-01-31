/*************************************************************************
  > File Name: 10891 - Game of Sum.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Oct 28 23:09:12 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, id;
int in[110];
int dp[110][110];
int visit[110][110];
int dfs(int i, int j) {
    int ans = -(1 << 30);
    if (i > j)
        return 0;
    if (visit[i][j] == id)
        return dp[i][j];
    visit[i][j] = id;
    int sumij = in[j] - in[i - 1];
    for (int k = 1; k <= j - i + 1; k++)
        ans = max(ans, sumij - min(dfs(i + k, j), dfs(i, j - k)));
    return dp[i][j] = ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        id++;
        for (int i = 1; i <= n; i++) {
            cin >> in[i];
            in[i] += in[i - 1];
        }
        memset(dp, 0, sizeof(dp));
        cout << 2 * dfs(1, n) - in[n] << '\n';
    }
    return 0;
}

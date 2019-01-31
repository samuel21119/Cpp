/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 24 23:11:34 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int dp[200001];
int data[200001];
int n;

int dfs(int i) {
    if (dp[i])
        return dp[i];
    if (i < n - 1 && data[i] * 2 >= data[i + 1])
        return dp[i] = 1 + dfs(i + 1);
    return dp[i];
}

int main() {
    ios::sync_with_stdio(0);

    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dfs(i));
    cout << ans + 1 << '\n';
    return 0;
}

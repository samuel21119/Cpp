/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Apr 15 22:43:49 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> road[200010];
int deep[200010];
int deg[200010];
int point[200010];
long long ans;
priority_queue<long long> que;
int dfs0(int now, int parent) {
    int child = 0;
    for (int i : road[now]) {
        if (i == parent)
            continue;
        deep[i] = deep[now] + 1;
        child += dfs0(i, now);
    }
    que.push(deep[now] - child);
    return child + 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        road[a].emplace_back(b);
        road[b].emplace_back(a);
        deg[a]++;
        deg[b]++;
    }
    dfs0(1, 1);
    while (k--) {
        ans += que.top();
        que.pop();
    }
    cout << ans << '\n';
    return 0;
}

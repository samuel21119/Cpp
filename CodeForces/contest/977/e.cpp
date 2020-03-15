/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Sep 28 12:32:37 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200010];
int n, m;
bool stat;
bool visit[200010];
int ans;
void dfs(int now, int parent, int father) {
    visit[now] = 1;
    int cnt = 0;
    for (int &i : graph[now]) {
        if (i == parent)
            continue;
        if (i == father) {
            cnt++;
            continue;
        }
        if (visit[i]) {
            cnt += now != father;
            continue;
        }
        cnt++;
        dfs(i, now, father);
    }
    stat &= cnt == 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        stat = 1;
        if (!visit[i]) {
            dfs(i, i, i);
            if (stat)
                ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}

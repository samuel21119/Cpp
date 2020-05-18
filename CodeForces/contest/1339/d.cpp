/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Apr 12 22:27:40 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> edge[100010];
vector<int> leaf;
bool isleaf[100010], vis[100010];
int mn, mx;
void dfs1(int now, int parent, int len) {
    if (isleaf[now] && len % 2)
        mn = 3;
    for (int i : edge[now])
        if (i != parent)
            dfs1(i, now, len + 1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (edge[i].size() == 1) {
            isleaf[i] = 1;
            leaf.emplace_back(i);
        }
    mn = 1;
    dfs1(leaf[0], 0, 0);
    mx = n - 1;
    for (int i : leaf) {
        if (vis[edge[i][0]])
            mx--;
        else
            vis[edge[i][0]] = 1;
    }
    cout << mn << ' ' << mx << '\n';
    return 0;
}

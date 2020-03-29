/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar 28 10:25:48 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> edge[200010];
vector<int> query[200010];
vector<int> bottom[200010];
bool can[200010], ans[200010];
int deep[200010];
void get_deep(int now, int parent, int dis) {
    deep[now] = dis;
    for (int i : edge[now]) {
        if (i == parent)
            continue;
        get_deep(i, now, dis + 1);
    }
}
void dfs(int now, int parent) {
    for (int i : edge[now])
        can[i] = 1;
    for (int i : bottom[now]) {
        bool c = 1;
        for (int j : query[i])
            c &= can[j];
        ans[i] = c;
    }
    for (int i : edge[now])
        if (i != parent)
            dfs(i, now);
    for (int i : edge[now])
        can[i] = 0;
    can[parent] = 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    can[1] = 1;
    get_deep(1, 1, 0);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int mx = 0, node = 1;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            query[i].emplace_back(a);
            if (deep[a] > mx) {
                mx = deep[a];
                node = a;
            }
        }
        bottom[node].emplace_back(i);
    }
    dfs(1, 1);
    for (int i = 0; i < m; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';
    return 0;
}

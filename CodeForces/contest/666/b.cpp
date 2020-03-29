/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar 21 23:55:13 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, m;
bool graph[3010][3010];
vector<int> graph2[3010], out;
int dis[3010][3010];
vector<pii> v1[3010], v2[3010]; //v2 : reverse
int ans;
void bfs(int start) {
    memset(dis[start], -1, sizeof(dis[0]));
    dis[start][start] = 0;
    queue<int> que;
    que.push(start);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i : graph2[cur]) {
            if (dis[start][i] != -1)
                continue;
            dis[start][i] = dis[start][cur] + 1;
            que.push(i);
        }
    }
}
bool check(int a, int b, int c, int d) {
    return a == c || b == d || a == d;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x == y || graph[x][y])
            continue;
        graph[x][y] = 1;
        graph2[x].emplace_back(y);
    }
    for (int i = 1; i <= n; i++)
        bfs(i);
    auto cmp = [&](pii a, pii b) {
        return a.second > b.second;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (dis[i][j] > 0) {
                v1[i].push_back({j, dis[i][j]});
                v2[j].push_back({i, dis[i][j]});
            }
    }
    for (int i = 1; i <= n; i++) {
        sort(v1[i].begin(), v1[i].end(), cmp);
        sort(v2[i].begin(), v2[i].end(), cmp);
    }
    for (int b = 1; b <= n; b++)
        for (int c = 1; c <= n; c++) {
            if (b == c || dis[b][c] <= 0)
                continue;
            int sizeB = v2[b].size();
            int sizeC = v1[c].size();
            for (int i = 0; i < min(2, sizeB); i++) {
                for (int j = 0; j < min(2, sizeC); j++) {
                    int a = v2[b][i].first;
                    int d = v1[c][j].first;
                    if (check(a, b, c, d))
                        continue;
                    int len = dis[a][b] + dis[b][c] + dis[c][d];
                    if (len > ans) {
                        ans = len;
                        out = {a, b, c, d};
                    }
                }
            }
        }
    for (int i : out)
        cout << i << ' ';
    return 0;
}

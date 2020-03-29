/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar 21 20:02:54 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int in[110][110];
int n, m;
bool vis[110][110];
int dis[110][110];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char a;
            cin >> a;
            in[i][j] = a != '.';
        }
    queue<pair<int, int>> q;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dis[i][j] = 1e9;
    dis[0][1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        int nx, ny;
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            if (in[x][y] == in[nx][ny] || (in[x][y] && !in[nx][ny]))
                dis[nx][ny] = min(dis[nx][ny], dis[x][y]);
            else
                dis[nx][ny] = min(dis[nx][ny], dis[x][y] + 1);
            if (!vis[nx][ny])
                q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    cout << dis[n][m] << '\n';
    return 0;
}

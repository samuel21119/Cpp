/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon May 18 18:18:34 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

bool in[1000][1000];
int vis[1000][1000];
int n, m, k;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool same(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 | nx >= n || ny >= m)
            continue;
        if (in[x][y] == in[nx][ny])
            return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            in[i][j] = a == '1';
        }
    queue<pii> que;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (same(i, j)) {
                vis[i][j] = 1;
                que.push({i, j});
            }
        }
    while (!que.empty()) {
        pii cur = que.front();
        que.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 | nx >= n || ny >= m || vis[nx][ny])
                continue;
            que.push({nx, ny});
            vis[nx][ny] = vis[x][y] + 1;
        }
    }
    while (k--) {
        int x, y;
        ll q;
        cin >> x >> y >> q;
        x--, y--;
        ll tmp = 0;
        if (vis[x][y])
            tmp = max(0LL, q - (vis[x][y] - 1));
        //cout << vis[x][y] << ' ';
        cout << (in[x][y] ^ (tmp & 1)) << '\n';
    }
    return 0;
}

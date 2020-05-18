/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed May  6 23:26:42 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
bool in[1010][1010];
bool southX[1010];
bool southY[1010];
bool northX[1010];
bool northY[1010];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
typedef pair<int, int> pii;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int cc = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            in[i][j] = x == '#';
            cc += in[i][j];
            if (in[i][j]) {
                southX[i] = southY[j] = 1;
                northX[i] = 1;
                northY[j] = 1;
            }
        }
    if (cc == 0) {
        cout << 0;
        return 0;
    }
    bool ans = 1;
    for (int i = 0; i < n; i++) {
        bool black = 0, white = 0;
        for (int j = 0; j < m; j++) {
            if (in[i][j]) {
                if (black && white)
                    ans = 0;
                black = 1;
            }else {
                if (black)
                    white = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        bool black = 0, white = 0;
        for (int j = 0; j < n; j++) {
            if (in[j][i]) {
                if (black && white)
                    ans = 0;
                black = 1;
            }else {
                if (black)
                    white = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (!northX[i] && !northY[j])
                southX[i] = southY[j] = 1;
        }
    for (int i = 0; i < n; i++)
        ans &= southX[i];
    for (int i = 0; i < m; i++)
        ans &= southY[i];
    if (ans == 0) {
        cout << "-1";
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (!in[i][j])
                continue;
            cnt++;
            queue<pii> q;
            q.push({i, j});
            while (!q.empty()) {
                pii cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || !in[nx][ny])
                        continue;
                    in[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    cout << cnt << '\n';
    return 0;
}

/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar  5 14:14:52 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
    int x, y;
    node() {}
    node(int a, int b) {
        x = a, y = b;
    }
    bool operator==(const node &b) const {
        return x == b.x && y == b.y;
    }
    bool operator!=(const node &b) const {
        return !(*this == b);
    }
}in[1010][1010];
char ans[1010][1010];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char dir[] = {'D', 'R', 'U', 'L'};
char r_dir[] = {'U', 'L', 'D', 'R'};
void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > n || in[nx][ny] != in[x][y] || ans[nx][ny] != 0)
            continue;
        ans[nx][ny] = r_dir[i];
        dfs(nx, ny);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a, b;
            cin >> a >> b;
            in[i][j] = {a, b};
            if (a == i && b == j)
                ans[i][j] = 'X';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (in[i][j] != node(-1, -1))
                continue;
            int cnt = 0;
            int can = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 1 || ny < 1 || nx > n || ny > n || in[nx][ny] != node(-1, -1))
                    continue;
                cnt++;
                can = k;
                if (ans[nx][ny] == 0) {
                    ans[i][j] = dir[k];
                    can = -1;
                    break;
                }
            }
            if (can != -1) {
                if (cnt < 1) {
                    cout << "INVALID\n";
                    return 0;
                }
                ans[i][j] = dir[can];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (ans[i][j] == 'X')
                dfs(i, j);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (ans[i][j] == 0) {
                cout << "INVALID\n";
                return 0;
            }
    cout << "VALID\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << ans[i][j];
        cout << '\n';
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <utility>
#define X first
#define Y second
using namespace std;
short m[2][8] = {{-2, -1, 1, 2, 2, 1, -1, -2}, {-1, -2, -2, -1, 1, 2, 2, 1}};
char sx, sy, ex, ey;
int dis[8][8];
set<string> ss;
void dfs(char x, char y, int count, string s) {
    char nx, ny;
    string sn;
    if (count == dis[ex][ey]) {
        if (x == ex && y == ey)
            ss.insert(s + (char)(x + 'a') + (char)(y + '1'));
    }
    else
        for (int i = 0; i < 8; i++) {
            nx = x + m[0][i];
            ny = y + m[1][i];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dis[nx][ny] != -2) {
                sn = s + (char)(x + 'a') + (char)(y + '1');
                if (count < dis[ex][ey])
                    sn += " ";
                dfs(nx, ny, count + 1, sn);
            }
        }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char a, b, nx, ny;
    pair<char, char> p, n;
    while (cin >> sx) {
        cin >> sy >> ex >> ey;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                dis[i][j] = -1;
        ss.clear();
        while (cin >> a >> b && a != 'x')
            dis[a-'a'][b-'1'] = -2;
        queue<pair<char, char> > que;
        sx -= 'a';
        sy -= '1';
        ex -= 'a';
        ey -= '1';
        p.X = sx; p.Y = sy;
        que.push(p);
        dis[sx][sy] = 0;
        while (!que.empty()) {
            p = que.front();
            que.pop();
            if (p.X == ex && p.Y == ey)
                break;
            for (int i = 0; i < 8; i++) {
                nx = p.X + m[0][i];
                ny = p.Y + m[1][i];
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dis[nx][ny] == -1) {
                    dis[nx][ny] = dis[p.X][p.Y] + 1;
                    n.X = nx; n.Y = ny;
                    que.push(n);
                }
            }
        }
        cout << "The shortest solution is " << dis[ex][ey] << " move(s).\n";
        dfs(sx, sy, 0, "");
        for (set<string>::iterator it = ss.begin(); it != ss.end(); it++)
            cout << "Solution: " << *it << '\n';
    }
}

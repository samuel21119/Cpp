/*************************************************************************
  > File Name: 10307 - Killing Aliens in Borg Maze.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Feb 27 16:19:08 2018
*************************************************************************/

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int moves[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};
struct xy{
    int x, y;
    xy(){}
    xy (int _x, int _y) : x(_x), y(_y) {}
};
struct dist {
    int a, b;
    int dis;
    dist(){}
    dist (int _a, int _b, int _dis) : a(_a), b(_b), dis(_dis) {}
    bool operator< (dist const& A) const {
        return dis < A.dis;
    }
}line[6000];
int in[51][51];
xy dots[110];
int run[60][60];
bool run2[110][110];
int x, y;
int parent[110];
int find_p (int target) {
    if (target != parent[target])
        parent[target] = find_p(parent[target]);
    return parent[target];
}
int main() {
    int c, d, l;
    cin >> c;
    while (c--) {
        char temp_input[60];
        cin >> x >> y;
        d = 0;
        l = 0;
        getchar();
        for (int i = 0; i < y; i++) {
            cin.getline(temp_input, 55);
            for (int j = 0; j < x; j++) {
                if (temp_input[j] == 'A' || temp_input[j] == 'S') {
                    in[i][j] = d;
                    dots[d++] = {i, j};
                }
                else if (temp_input[j] == '#')
                    in[i][j] = -1;
                else
                    in[i][j] = -2;
            }
        }
        memset(run2, true, sizeof(run2));
        for (int i = 0; i < d; i++)
            run2[i][i] = false;
        for (int i = 0; i < d; i++) {
            xy start, now;
            start = {dots[i].x, dots[i].y};
            int startN = in[start.x][start.y];
            int nowN;
            queue<xy> que;
            que.push(start);
            for (int i = 0; i < y; i++)
                for (int j = 0; j < x; j++)
                    run[i][j] = -1;
            run[start.x][start.y] = 0;
            while (!que.empty()) {
                now = que.front();
                que.pop();
                nowN = in[now.x][now.y];
                if (nowN >= 0 && run2[nowN][startN]) {
                    line[l++] = {nowN, startN, run[now.x][now.y]};
                    run2[nowN][startN] = run2[startN][nowN] = false;
                }
                for (int i = 0; i < 4; i++) {
                    int nx, ny;
                    nx = now.x + moves[0][i];
                    ny = now.y + moves[1][i];
                    if (in[nx][ny] == -1 || run[nx][ny] != -1)
                        continue;
                    run[nx][ny] = run[now.x][now.y] + 1;
                    que.push((xy){nx, ny});
                }
            }
        }
        sort(line, line + l);
        for (int i = 0; i < d; i++)
            parent[i] = i;
        int ans = 0;
        for (int i = 0, choosen = 1; choosen < d; i++) {
            int a, b, ap, bp;
            a = line[i].a;
            b = line[i].b;
            ap = find_p(a);
            bp = find_p(b);
            if (ap == bp)
                continue;
            parent[bp] = ap;
            ans += line[i].dis;
            choosen++;
            //cout << choosen - 1 << ' ' << i<< ' ' << l  << endl;
        }
        cout << ans << '\n';
    }
}

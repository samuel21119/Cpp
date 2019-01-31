/*************************************************************************
  > File Name: 00838 - Worm World.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Oct  2 17:06:29 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int in[12][12];
int d[2][4] = {{-1, 0, 1, 0}, {0, -1, 0, 1}};
bool visit[1001];
int ans, cnt, n, t, c, ni, nj, steps;
void dfs(int i, int j) {
    if (ans == cnt)
        return;
    visit[in[i][j]] = 0;
    for (int k = 0; k < 4; k++) {
        ni = i + d[0][k];
        nj = j + d[1][k];
        if (nj < 0 || ni < 0 || nj == n || ni == n)
            continue;
        if (!visit[in[ni][nj]])
            continue;
        steps++;
        dfs(ni, nj);
        steps--;
    }
    ans = max(ans, steps);
    visit[in[i][j]] = 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (cin >> c; t < c; ) {
        cin >> n;
        cnt = ans = 0;
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> in[i][j];
                if (!visit[in[i][j]])
                    visit[in[i][j]] = 1, cnt++;
            };
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                steps = 1;
                dfs(i, j);
            }
        cout << ans << '\n';
        if (++t < c)
            cout << '\n';
    }
    return 0;
}

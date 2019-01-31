/*************************************************************************
  > File Name: 11882 - Biggest Number.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Oct 28 23:41:26 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string ans;
int n, m, nm;
char graph[20][20];
bool visit[20][20], visit2[20][20];
int d[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
bool cmp(string &s1, string &s2) {
    if (s1.length() < s2.length())
        return 1;
    if (s1.length() > s2.length())
        return 0;
    return s1 < s2;
}
int bfs(int i, int j) {
    memcpy(visit2, visit, sizeof(visit));
    int len = 0;
    pair<int, int> cur;
    queue<pair<int, int>> que;
    que.push({i, j});
    while (!que.empty()) {
        cur = que.front();
        que.pop();
        for (int k = 0; k < 4; k++) {
            int ni = cur.first + d[0][k];
            int nj = cur.second + d[1][k];
            if (!ni || !nj || ni > n || nj > m || graph[ni][nj] == '#' || visit2[ni][nj])
                continue;
            visit2[ni][nj] = 1;
            len++;
            que.push({ni, nj});
        }
    }
    return len;
}
void dfs(int i, int j, string num) {
    unsigned tmp = num.length() + bfs(i, j);
    if (tmp < ans.length())
        return;
    if (cmp(ans, num))
        ans = num;
    if (tmp == ans.length() && num + 'z' < ans) {
        return;
    }
    for (int k = 0; k < 4; k++) {
        int ni = d[0][k] + i;
        int nj = d[1][k] + j;
        if (!ni || !nj || ni > n || nj > m || graph[ni][nj] == '#' || visit[ni][nj])
            continue;
        visit[ni][nj] = 1;
        dfs(ni, nj, num + graph[ni][nj]);
        visit[ni][nj] = 0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m && n) {
        nm = n * m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> graph[i][j];
        ans = "";
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (graph[i][j] != '#') {
                    visit[i][j] = 1;
                    dfs(i, j, string(1, graph[i][j]));
                    visit[i][j] = 0;
                }
        cout << ans << '\n';
    }
    return 0;
}

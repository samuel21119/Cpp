/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat May 16 22:56:27 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int tt;
int n, m;
int X[110], Y[110];
int link[110][110];
int ans[110][110];
int t;
int vis[110];
void dfs(int now) {
    vis[now] = 1;
    for (int i = 1; i < n; i++) {
        if (link[now][i] && X[i] > X[now] && vis[i] == 0) {
            ans[now][i] = ans[i][now] = X[i] - X[now];
            dfs(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    for (int a = 1; a <= tt; a++) {
        memset(link, 0, sizeof(link));
        memset(ans, 0, sizeof(ans));
        memset(vis, 0, sizeof(vis));
        cin >> n >> m;
        pair<int, int> road2[1100];
        for (int i = 1; i < n; i++) {
            int a;
            cin >> a;
            assert(a < 0);
            X[i] = -a;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            road2[i] = {a, b};
            link[a][b] = 1;
            link[b][a] = 1;
        }
        t = 1;
        dfs(0);
        cout << "Case #" << a << ": ";
        for (int i = 0; i < m; i++) {
            int a, b;
            a = road2[i].first;
            b = road2[i].second;
            int x = ans[a][b];
            if (x)
                cout << x << ' ' ;
            else
                cout << 1000000 << ' ';
        }
        cout << '\n';
    }
    return 0;
}

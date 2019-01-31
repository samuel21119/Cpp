/*************************************************************************
  > File Name: 00193 - Graph Coloring.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Oct  8 23:01:27 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k, ans, a, b, c;
bool graph[110][110];
int visit[110], out[110], tmp[110];
void dfs(int now, int color) {
    if (now > n) {
        if (ans < color) {
            ans = color;
            for (int i = 1; i <= n; i++)
                out[i] = tmp[i];
        }
        return;
    }
    for (int i = now; i <= n; i++) {
        if (tmp[i])
            continue;
        tmp[i] = i;
        for (int j = 1; j <= n; j++)
            if (graph[i][j] && !tmp[j])
                tmp[j] = i;
        int nxt = i + 1;
        while (tmp[nxt])
            nxt++;
        dfs(nxt, color + 1);
        for (int j = 1; j <= n; j++)
            if (tmp[j] == i)
                tmp[j] = 0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    while (c--) {
        cin >> n >> k;
        ans = 0;
        memset(graph, 0, sizeof(graph));
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            graph[a][b] = graph[b][a] = 1;
        }
        dfs(1, 0);
        cout << ans << '\n';
        k = 0;
        for (int i = 1; i <= n && ans; i++) {
            if (out[i] == i) {
                if (k)
                    cout << ' ';
                k = 1;
                cout << i;
            }
        }
        cout << '\n';
    }
    return 0;
}

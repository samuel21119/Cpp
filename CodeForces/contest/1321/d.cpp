/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Mar  2 23:45:16 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> link[200010], reverse_link[200010];
int n, m;
int bfs[200010], o, k[200010];
int s, e;
int mx, mn;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        link[a].emplace_back(b);
        reverse_link[b].emplace_back(a);
    }
    cin >> o;
    for (int i = 0; i < o; i++)
        cin >> k[i];
    s = k[0];
    e = k[o - 1];
    queue<int> q;
    q.push(e);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : reverse_link[cur]) {
            if (i == e || bfs[i] > 0)
                continue;
            bfs[i] = bfs[cur] + 1;
            q.push(i);
        }
    }
    int cur = k[0];
    o--;
    for (int i = 1; i < o; cur = k[i++]) {
        int next = k[i];
        if (bfs[cur] == bfs[next] + 1) {
            for (int i : link[cur]) {
                if (i != next && bfs[i] == bfs[next])
                    mx++, break;
            }
        }else
            mn++, mx++;
    }
    cout << mn << ' ' << mx << '\n';
    return 0;
}

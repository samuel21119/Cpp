/*************************************************************************
  > File Name: 10080 - Gopher II.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Sep  7 18:56:37 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int parent[202];
int flow[200][200];
int n, m, s, v, e, ans;
double max_dist;
struct xy {
    double x, y;
    xy() {}
    xy(int x, int y) : x(x), y(y) {}
}gopher[100], hole[100];
double dist(xy a, xy b) {
    double x = a.x - b.x;
    double y = a.y - b.y;
    x *= x;
    y *= y;
    return sqrt(x + y);
}
void max_flow() {
    ans = 0;
    bool find;
    int cur;
    while(1) {
        queue<int> q;
        q.push(0);
        find = 0;
        for (int i = 1; i <= e; i++)
            parent[i] = i;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur == e) {
                find = 1;
                break;
            }
            for (int i = 1; i <= e; i++) {
                if (flow[cur][i] > 0 && parent[i] == i) {
                    parent[i] = cur;
                    q.push(i);
                }
            }
        }
        if (!find)
            return;
        ans++;
        cur = e;
        while (cur) {
            flow[cur][parent[cur]]++;
            flow[parent[cur]][cur]--;
            cur = parent[cur];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m >> s >> v) {
        max_dist = s * v;
        e = n + m + 1;
        for (int i = 0; i < n; i++)
            cin >> gopher[i].x >> gopher[i].y;
        for (int i = 0; i < m; i++)
            cin >> hole[i].x >> hole[i].y;
        memset(flow, 0, sizeof(flow));
        for (int i = 0; i < n; i++) {
            flow[0][i + 1] = 1;
            for (int j = 0; j < m; j++)
                if (dist(gopher[i], hole[j]) <= max_dist)
                    flow[i + 1][n + j + 1] = 1;
        }
        for (int i = 0; i < m; )
            flow[n + ++i][e] = 1;
        max_flow();
        cout << n - ans << '\n';
    }
    return 0;
}

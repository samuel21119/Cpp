/*************************************************************************
  > File Name: b686.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Oct 29 21:54:28 2018
*************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n, m, r, a, b, c;
int graph[510][510];
int graph2[510];
int defend[510];
vector<int> link[510];
typedef pair<int, int> pii;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        cin >> defend[i];
    while (m--) {
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
        link[a].emplace_back(b);
        link[b].emplace_back(a);
    }
    while (r--) {
        int atk, s, e, cur, dis;
        cin >> atk >> s >> e;
        if (defend[s] < atk || defend[e] < atk) {
            cout << "-1\n";
            continue;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
        memset(graph2, 127, sizeof(graph2));
        graph2[s] = 0;
        while (!pq.empty()) {
            cur = pq.top().second;
            dis = pq.top().first;
            pq.pop();
            if (graph2[cur] < dis)
                continue;
            for (int &i : link[cur]) {
                if (defend[i] < atk)
                    continue;
                if (graph2[i] > dis + graph[cur][i]) {
                    graph2[i] = dis + graph[cur][i];
                    pq.push({graph2[i], i});
                }
            }
        }
        if (graph2[e] == graph2[509])
            cout << "-1\n";
        else
            cout << graph2[e] << '\n';
    }
    return 0;
}

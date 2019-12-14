/*************************************************************************
  > File Name: 00336 - A Node Too Far.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 14 21:08:15 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int node;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases = 1;
    while (cin >> n && n) {
        map<int, vector<int>> link;
        while (n--) {
            int a, b;
            cin >> a >> b;
            link[a].emplace_back(b);
            link[b].emplace_back(a);
        }
        node = link.size();
        int start, ttl;
        while (cin >> start >> ttl && (start + ttl)) {
            map<int, int> vis;
            queue<int> que;
            que.push(start);
            int cnt = 1;
            while (!que.empty()) {
                int cur = que.front();
                que.pop();
                int time = vis[cur];
                if (time >= ttl)
                    continue;
                for (int i : link[cur]) {
                    if (i == start || vis[i] != 0)
                        continue;
                    vis[i] = time + 1;
                    que.push(i);
                    cnt++;
                }
            }
            cout << "Case " << cases++ << ": " << node - cnt << " nodes not reachable from node " << start << " with TTL = " << ttl << ".\n";
        }
    }
    return 0;
}

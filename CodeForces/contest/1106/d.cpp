/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed 06 Feb 2019 09:46:22 AM CST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> edge[100010];
bool visit[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    visit[1] = 1;
    while (!pq.empty()) {
        int i = pq.top();
        pq.pop();
        cout << i << ' ';
        for (int j : edge[i]) {
            if (visit[j])
                continue;
            visit[j] = 1;
            pq.push(j);
        }
    }
    cout << '\n';
    return 0;
}

/*************************************************************************
  > File Name: 10765 - Doves and Bombs.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Dec 12 11:22:17 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, cases;
vector<int> edge[10010];

int bcc[10010];
stack<int> sta;
int dfs_time;
int result[10010], visit[10010], low[10010];
int bcc_cnt;
bool is_cut[10010];
struct S {
    int x, cnt;
    S() {}
    S(int a, int b) {
        x = a, cnt = b;
    }
    bool operator< (const S &b) const {
        if (cnt == b.cnt)
            return x < b.x;
        return cnt > b.cnt;
    }
}data[10010];
void dfs(int now, int parent) {
    sta.push(now);
    visit[now] = low[now] = ++dfs_time;
    for (int i : edge[now]) {
        if (!visit[i])
            dfs(i, now);
        if (i != parent)
            low[now] = min(low[now], low[i]);
    }
    if (low[now] == visit[now]) {
        int t;
        bcc[bcc_cnt] = 0;
        do {
            t = sta.top(); sta.pop();
            result[t] = bcc_cnt;
            bcc[bcc_cnt]++;
        }while (t != now);
        bcc_cnt++;
    }
}
inline void init() {
    memset(is_cut, 0, sizeof(is_cut));
    memset(visit, 0, sizeof(visit));
    dfs_time = bcc_cnt = 0;
    while (!sta.empty()) sta.pop();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m && (n + m)) {
        for (int i = 0; i < n; i++)
            edge[i].clear();
        while (cin >> a >> b && (a + b) != -2) {
            edge[a].emplace_back(b);
            edge[b].emplace_back(a);
        }
        init();
        dfs(0, 0);
        for (int i = 0; i < n; i++) {
            int cnt = bcc[result[i]] > 1;
            for (int j : edge[i])
                cnt += result[i] != result[j];
            data[i] = {i, cnt};
        }
        sort(data, data + n);
        for (int i = 0; i < m; i++)
            cout << data[i].x << ' ' << data[i].cnt << '\n';
    }
    return 0;
}

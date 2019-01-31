/*************************************************************************
  > File Name: 11324 - The Largest Clique.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Dec 12 17:00:21 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<int> link[maxn];
set<int> link2[maxn];
int sta[maxn], ptr;
int dfs_time, id;
int visit[maxn], low[maxn];
bool in_stack[maxn];
int result[maxn], value[maxn], dp[maxn];
int n, m, ans;
void scc(int now) {
    visit[now] = low[now] = ++dfs_time;
    sta[ptr++] = now;
    in_stack[now] = 1;
    for (int &i : link[now]) {
        if (!visit[i])
            scc(i);
        if (in_stack[i])
            low[now] = min(low[now], low[i]);
    }
    if (visit[now] == low[now]) {
        int tmp;
        value[id] = 0;
        do {
            in_stack[tmp = sta[--ptr]] = 0;
            result[tmp] = id;
            value[id]++;
        } while (tmp != now);
        id++;
    }
}
inline void run_scc() {
    memset(visit, 0, sizeof(visit));
    memset(in_stack, 0, sizeof(in_stack));
    id = 1;
    dfs_time = ptr = 0;
    for (int i = 1; i <= n; i++)
        if (!visit[i])
            scc(i);
}
int dfs(int x) {
    if (dp[x])
        return dp[x];
    for (int i : link2[x])
        dp[x] = max(dp[x], dfs(i));
    return dp[x] += value[x];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            link[i].clear();
        while (m--) {
            int a, b;
            cin >> a >> b;
            link[a].emplace_back(b);
        }
        run_scc();
        for (int i = 1; i < id; i++)
            link2[i].clear();
        for (int i = 1; i <= n; i++)
            for (int &j : link[i])
                if (result[i] != result[j])
                    link2[result[i]].insert(result[j]);
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for (int i = 1; i < id; i++)
            ans = max(ans, dfs(i));
        cout << ans << '\n';
    }
    return 0;
}

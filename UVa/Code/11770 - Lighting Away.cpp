/*************************************************************************
  > File Name: 11770 - Lighting Away.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Dec 13 08:36:17 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n, m, a, b, t, ans;
vector<int> link[maxn];
int sta[maxn], ptr;
int dfs_time, id;
int visit[maxn], low[maxn], result[maxn];
bool in_stack[maxn];

bool cnt[maxn];
void scc(int now) {
    visit[now] = low[now] = ++dfs_time;
    in_stack[now] = 1;
    sta[ptr++] = now;
    for (int &i : link[now]) {
        if (!visit[i])
            scc(i);
        if (in_stack[i])
            low[now] = min(low[now], low[i]);
    }
    if (visit[now] == low[now]) {
        int tmp;
        do {
            in_stack[tmp = sta[--ptr]] = 0;
            result[tmp] = id;
        } while (tmp != now);
        id++;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            link[i].clear();
        while (m--) {
            cin >> a >> b;
            link[a].emplace_back(b);
        }
        //scc start
        memset(visit, 0, sizeof(visit));
        memset(in_stack, 0, sizeof(in_stack));
        ptr = 0;
        id = 1;
        for (int i = 1; i <= n; i++)
            if (!visit[i])
                scc(i);
        //scc end
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i <= n; i++)
            for (int &j : link[i])
                if (result[i] != result[j])
                    visit[result[j]] = 1;
        ans = 0;
        for (int i = 1; i < id; i++)
            ans += !visit[i];
        cout << "Case " << i << ": " << ans << '\n';
    }
    return 0;
}

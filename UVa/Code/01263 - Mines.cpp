/*************************************************************************
  > File Name: 01263 - Mines.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Dec 13 14:15:05 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int t, n, a, b, c, ans;
vector<int> link[maxn];
struct mines {
    int x, y;
    int range;
    mines() {}
    mines(int a, int b, int c) {
        x = a;
        y = b;
        range = c;
    }
}in[maxn];
inline bool inrange(int i, int j) {
    bool x = (in[j].x <= in[i].x + in[i].range) && (in[i].x - in[i].range <= in[j].x);
    bool y = (in[j].y <= in[i].y + in[i].range) && (in[i].y - in[i].range <= in[j].y);
    return x && y;
}
int sta[maxn], ptr;
int visit[maxn], low[maxn], dfs_time, id;
int result[maxn];
bool cnt[maxn];
bool in_stack[maxn];
void scc(int x) {
    visit[x] = low[x] = ++dfs_time;
    in_stack[x] = 1;
    sta[ptr++] = x;
    for (int &i : link[x]) {
        if (!visit[i])
            scc(i);
        if (in_stack[i])
            low[x] = min(low[x], low[i]);
    }
    if (visit[x] == low[x]) {
        int tmp;
        do {
            in_stack[tmp = sta[--ptr]] = 0;
            result[tmp] = id;
        } while (tmp != x);
        id++;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            link[i].clear();
            cin >> a >> b >> c;
            in[i] = {a, b, c / 2};
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && inrange(i, j))
                    link[i].emplace_back(j);
        //scc start
        memset(visit, 0, sizeof(visit));
        memset(cnt, 0, sizeof(cnt));
        memset(in_stack, 0, sizeof(in_stack));
        id = 1;
        dfs_time = ptr = 0;
        for (int i = 1; i <= n; i++)
            if (!visit[i])
                scc(i);
        //scc end
        for (int i = 1; i <= n; i++)
            for (int &j : link[i])
                if (result[i] != result[j])
                    cnt[result[j]] = 1;
        ans = 0;
        for (int i = 1; i < id; i++)
            ans += !cnt[i];
        cout << ans << '\n';
    }
    return 0;
}

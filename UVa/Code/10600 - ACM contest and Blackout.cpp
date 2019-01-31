/*************************************************************************
  > File Name: 10600 - ACM contest and Blackout.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep 20 12:17:39 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m;
struct l {
    int a, b;
    int val;
    bool operator< (const l &b) const {
        return val < b.val;
    }
    l() {}
    l(int a, int b, int v) : a(a), b(b), val(v) {}
};
vector<l> line;

vector<pair<int,int>> mst[maxn];
int parent[maxn], ans1, ans2;

int logn;
vector<int> dp[maxn], maxdp[maxn];
int deep[maxn];

int find(int i) {
    if (i == parent[i])
        return i;
    return parent[i] = find(parent[i]);
}
void MST() {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        mst[i].clear();
    }
    int cnt = 0;
    for (auto &i : line) {
        int a = find(i.a);
        int b = find(i.b);
        if (a == b)
            continue;
        parent[b] = a;
        mst[i.a].emplace_back(make_pair(i.b, i.val));
        mst[i.b].emplace_back(make_pair(i.a, i.val));
        ans1 += i.val;
        i.val = 0;
        if (++cnt == n - 1)
            break;
    } 
}
void dfs(int now, int parent, int len) {
    dp[now].resize(logn);
    maxdp[now].resize(logn);
    dp[now][0] = parent;
    maxdp[now][0] = len;
    for (int i = 0; i + 1 < logn; i++) {
        dp[now][i + 1] = dp[dp[now][i]][i];
        maxdp[now][i + 1] = max(maxdp[now][i], maxdp[dp[now][i]][i]);
    }
    for (auto &i : mst[now]) {
        if (i.first == parent)
            continue;
        deep[i.first] = deep[now] + 1;
        dfs(i.first, now, i.second);
    }
}
int LCA(int a, int b) {
    if (deep[a] < deep[b])
        swap(a, b);
    int mx = -1;
    for (int i = deep[a] - deep[b], k = 0; i; i >>= 1, k++)
        if (i & 1) {
            mx = max(mx, maxdp[a][k]);
            a = dp[a][k];
        }
    if (a == b)
        return mx;
    for (int i = logn - 1; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) {
            mx = max(mx, max(maxdp[a][i], maxdp[b][i]));
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return max(max(mx, maxdp[a][0]), maxdp[b][0]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m;
        line.resize(m);
        for (int i = 0; i < m; i++) {
            int a, b, v;
            cin >> a >> b >> v;
            a--; b--;
            line[i] = {a, b, v};
        }
        sort(line.begin(), line.end());
        ans1 = ans2 = 0;
        MST();
        logn = log2(n) + 1;
        dfs(0, 0, 0);
        ans2 = 1 << 30;
        for (auto &i : line) {
            if (!i.val)
                continue;
            ans2 = min(ans2, i.val - LCA(i.a, i.b));
        }
        cout << ans1 << ' ' << ans1 + ans2 << '\n';
    }
    return 0;
}

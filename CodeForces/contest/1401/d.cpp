/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 21 23:59:13 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
ll p[100010];
ll kid[100010];
vector<ll> edges;
vector<int> tree[100010];
int n, m;
int dfs(int now, int pa) {
    ll kids = 0;
    for (int i : tree[now]) {
        if (i == pa)
            continue;
        ll tmp = dfs(i, now);
        kids += tmp;
    }
    return kid[now] = kids + 1;
}
void dfs2(int now, int pa) {
    for (int i : tree[now]) {
        if (i == pa)
            continue;
        ll tmp = kid[i] * (n - kid[i]);
        edges.emplace_back(tmp);
        dfs2(i, now);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        edges.clear();
        for (int i = 1; i <= n; i++)
            tree[i].clear();
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            tree[a].emplace_back(b);
            tree[b].emplace_back(a);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> p[i];
        for (int i = m; i < n - 1; i++) {
            p[i] = 1;
            m = n - 1;
        }
        sort(p, p + m);
        while (m >= n) {
            p[m - 2] = p[m - 1] * p[m - 2] % mod;
            m--;
        }
        dfs(1, 1);
        dfs2(1, 1);
        sort(edges.begin(), edges.end());
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            //cout << edges[i] << ' ';
            ans = (ans + p[i] * edges[i]) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}

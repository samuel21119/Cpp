#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> link[1001];
int sz[1001];
set<int> start;
bool vis[1001];
inline int query(int a, int b) {
    int re;
    cout << "? " << a << ' ' << b << endl;
    cin >> re;
    return re;
}
void dfs(int now, int p, int e) {
    auto it = start.find(now);
    if (it != start.end())
        start.erase(it);
    vis[now] = 1;
    for (int i : link[now])
        if (i != p && i != e && !vis[i])
            dfs(i, now, e);
}
int solve() {
    while (start.size() > 1) {
        int a = *start.begin(); start.erase(start.begin());
        int b = *start.begin(); start.erase(start.begin());
        int pa = query(a, b);
        if (pa == a || pa == b)
            return pa;
        dfs(a, a, pa);
        dfs(b, b, pa);
        sz[pa] -= 2;
        if (sz[pa] <= 1)
        start.insert(pa);
    }
    return *start.begin();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        link[a].emplace_back(b);
        link[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sz[i] = link[i].size();
        if (link[i].size() == 1)
            start.insert(i);
    }
    int ans = solve();
    cout << "! " << ans << '\n';
    return 0;
}

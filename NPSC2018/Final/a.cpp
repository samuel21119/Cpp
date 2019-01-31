#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
int n, s, l, r;
long long ans;
vector<int> link[200010];
int deep[200010];
void dfs(int now, int p) {
    for (int &i : link[now]) {
        if (i == p)
            continue;
        deep[i] = deep[now] + 1;
        dfs(i, now);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s >> l >> r;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        link[a].eb(b);
        link[b].eb(a);
    }
    dfs(s, s);
    for (int i = l; i <= r; i++) {
        ans += 1 + deep[i];
    }
    cout << ans << '\n';
}

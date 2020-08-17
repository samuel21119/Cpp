/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Aug 13 16:24:48 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const ll mod1 = 1e9, mod2 = 99999989;
int n, m, k, ans;
vector<pii> graph[200010];
//bst cnt[10][10], same, blank;
ll ha[200010], cnt1[10][10], cnt2[10][10], ans1, ans2;
void dfs(int x, ll st1, ll st2) {
    if (x == k + 1) {
        ans += st1 == ans1 && st2 == ans2;
        return;
    }
    for (int i = 1; i <= x; i++)
        dfs(x + 1, st1 * cnt1[x][i] % mod1, (st2 + cnt2[x][i]) % mod2);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({w, v2});
    }
    srand(time(NULL));
    ans1 = 1;
    for (int i = 1; i <= n; i++) {
        ha[i] = rand() % (mod2 / 2);
        ans1 = ans1 * ha[i] % mod1;
        ans2 = (ans2 + ha[i]) % mod2;
    }
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            cnt1[i][j] = 1;
    for (int i = 1; i <= n; i++) {
        int sz = graph[i].size();
        sort(graph[i].begin(), graph[i].end());
        for (int j = 1; j <= sz; j++) {
            int nxt = graph[i][j - 1].second;
            cnt1[sz][j] = cnt1[sz][j] * ha[nxt] % mod1;
            cnt2[sz][j] = (cnt2[sz][j] + ha[nxt]) % mod2;
        }
    }
    dfs(1, 1, 0);
    cout << ans << '\n';
    return 0;
}

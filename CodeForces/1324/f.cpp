/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 12 22:14:14 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int cnt[200010];
vector<int> link[200010];
int n;
bool color[200010];
int ans[200010];
int dfs1(int now, int parent) {
    int ans = color[now] ? 1 : -1;
    for (int i : link[now]) {
        if (i == parent)
            continue;
        int t = dfs1(i, now);
        if (t > 0)
            ans += t;
    }
    return cnt[now] = ans;
}
void dfs2(int now, int parent, int sum) {
    if (sum < 0)
        sum = 0;
    ans[now] = sum + cnt[now];
    for (int i : link[now]) {
        if (i == parent)
            continue;
        int t = sum + cnt[now];
        if (cnt[i] > 0)
            t -= cnt[i];
        dfs2(i, now, t);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        link[a].emplace_back(b);
        link[b].emplace_back(a);
    }
    dfs1(1, 1);
    cout << endl;
    dfs2(1, 1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}

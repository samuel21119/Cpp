/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep 20 10:39:19 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int n;
vector<int> edge[100010];
int sz[100010], mx;
vector<int> centroid;
int dfs(int now, int pa) {
    sz[now] = 1;
    int mxSize = 0;
    for (int i : edge[now]) {
        if (i == pa)
            continue;
        int tmp = dfs(i, now);
        mxSize = max(mxSize, tmp);
        sz[now] += tmp;
    }
    int tmp = max(mxSize, n - sz[now]);
    if (tmp < mx) {
        mx = tmp;
        centroid.clear(); 
        centroid.emplace_back(now);
    }else if (tmp == mx)
        centroid.emplace_back(now);
    return sz[now];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            edge[i].clear();
        mx = 1 << 30;
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            edge[a].emplace_back(b);
            edge[b].emplace_back(a);
        }
        dfs(1, 1);
        if (centroid.size() < 2) {
            cout << 1 << ' ' << edge[1].front() << '\n';
            cout << 1 << ' ' << edge[1].front() << '\n';
        }else {
            int A = centroid[0];
            int B = centroid[1];
            int tmp = edge[A][edge[A][0] == B];
            cout << A << ' ' << tmp << '\n';
            cout << B << ' ' << tmp << '\n';
        }
    }
    return 0;
}

/*************************************************************************
  > File Name: F.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed May 30 21:49:14 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, m, MAX;
int input[1<<23];
bool visit[1<<23];
bool p[1<<23];
int ans;
void dfs(int x) {
    if (visit[x])
        return;
    visit[x] = 1;
    if (p[x])
        dfs(x ^ MAX);
    for (int i = 0; i < n; i++)
        if (x & 1 << i)
            dfs(x ^ (1 << i));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    MAX = (1 << n) - 1;
    for (int i = 0; i < m; i++) cin >> input[i], p[input[i]] = 1;
    for (int i = 0; i < m; i++) visit[input[i]] = 0;
    for (int i = 0; i < m; i++) if (!visit[input[i]]) {dfs(input[i] ^ MAX); ans++;}
    cout << ans << '\n';
    return 0;
}

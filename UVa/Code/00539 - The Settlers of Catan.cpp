/*************************************************************************
  > File Name: 00539 - The Settlers of Catan.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Jul 14 17:41:54 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, m, t1, t2;
bool road[26][26];

void dfs(int j, int length) {
    for (int i = 0; i < n; i++)
        if (road[i][j]) {
            road[i][j] = road[j][i] = 0;
            dfs(i, length + 1);
            road[i][j] = road[j][i] = 1;
        }
    t1 = max(t1, length);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m && n && m) {
        memset(road, 0, sizeof(road));
        for (int i = 0; i < m; i++) {
            cin >> t1 >> t2;
            road[t1][t2] = road[t2][t1] = 1;
        }
        t1 = 0;
        for (int i = 0; i < n; i++)
            dfs(i, 0);
        cout << t1 << '\n';
    }
    return 0;
}

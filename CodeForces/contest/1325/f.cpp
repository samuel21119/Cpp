/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Mar 16 15:15:55 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> link[100010];
int deep[100010];
stack<int> sta;
int sq;
bool color[100010];
bool dfs(int x) {
    sta.push(x);
    deep[x] = sta.size();
    for (int i : link[x]) {
        if (deep[i]) {
            if (deep[x] - deep[i] + 1 >= sq) {
                cout << "2\n" << deep[x] - deep[i] + 1 << '\n';
                while (sta.top() != i) {
                    cout << sta.top() << ' ';
                    sta.pop();
                }
                cout << i << '\n';
                return 1;
            }
        }else {
            if (dfs(i))
                return 1;
        }
    }
    if (!color[x])
        for (int i : link[x])
            color[i] = 1;
    sta.pop();
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    sq = sqrt(n); sq += sq * sq != n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        link[a].emplace_back(b);
        link[b].emplace_back(a);
    }
    if (!dfs(1)) {
        cout << "1\n";
        for (int i = 1; sq; i++)
            if (!color[i]) {
                cout << i << ' ';
                sq--;
            }
    }
    return 0;
}

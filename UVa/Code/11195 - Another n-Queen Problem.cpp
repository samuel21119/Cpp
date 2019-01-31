/*************************************************************************
  > File Name: 11195 - Another n-Queen Problem.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 10 16:53:01 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool in[15][15];
int n, t, ans;
char c;
void dfs(int index, int leftState, int rightState, int straight) {
    if (index == n) {
        ans++;
        return;
    }
    for (int i = 0, pos = 1; i < n; i++, pos <<= 1) {
        if (in[index][i] || straight & pos || leftState & pos || rightState & pos)
            continue;
        dfs(index + 1, (leftState | pos) << 1, (rightState | pos) >> 1, straight | pos);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> c;
                in[i][j] = c == '*';
            }
        ans = 0;
        dfs(0, 0, 0, 0);
        cout << "Case " << ++t << ": " << ans << '\n';
    }
    return 0;
}

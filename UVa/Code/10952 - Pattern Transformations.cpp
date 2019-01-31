/*************************************************************************
  > File Name: 10952 - Pattern Transformations.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Jul 28 11:22:06 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;
int n, m, c;
char s[8][8], e[8][8];
int dp[8][1 << 8][1 << 8], run[8][1 << 8][1 << 8];
int dfs(int, int, int, int, int, int);
int sol(int, int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    while (c--) {
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> s[i][j];
            for (int j = 0; j < m; j++)
                cin >> e[i][j];
        }
        int ans = sol(0, 0, (1 << m) - 1);
        cout << (ans == inf ? -1 : ans) << '\n';
    }
    return 0;
}
int sol(int row, int prev_ver, int prev_hor) { //垂直 平行
    if (row == n)
        return (!prev_ver && prev_hor == (1 << m) - 1) ? 0 : inf;
    if (run[row][prev_ver][prev_hor] == c)
        return dp[row][prev_ver][prev_hor];
    run[row][prev_ver][prev_hor] = c;
    return dp[row][prev_ver][prev_hor] = dfs(row, 0, prev_ver, prev_hor, 0, 0);
}
int dfs(int row, int col, int prev_ver, int prev_hor, int now_ver, int now_hor) {
    while (1) {
        int re = inf;
        int col1 = 1 << col;
        if (col == m) {
            if (prev_hor != (1 << m) - 1)
                return inf;
            for (int i = 0; i < m; i++)
                if (e[row][i] == '.')
                    now_hor |= 1 << i;
            return sol(row + 1, now_ver, now_hor);
        }
        if (prev_ver & col1) {
            if (now_hor & col1)
                return inf;
            now_hor |= col1;
        }
        if (s[row][col] == '.') {
            if (!(prev_hor & col1))
                return inf;
            if (e[row][col] == '.')
                now_hor |= col1;
            col++;
            continue;
        }
        
        if (!(prev_hor & col1)) {
            if (s[row][col] != e[row - 1][col])
                return inf;
            if (prev_ver & col1)
                return 1 + dfs(row, col + 1, prev_ver, prev_hor | col1, now_ver, now_hor);
            prev_hor |= col1;
            col++;
            continue;
        }
        if (s[row][col] == e[row][col] && !(prev_ver & col1) && !(now_hor & col1))
            re = min(re, dfs(row, col + 1, prev_ver, prev_hor, now_ver, now_hor | col1));

        if (col < m - 1 && s[row][col] == e[row][col + 1])
            re = min(re, dfs(row, col + 1, prev_ver, prev_hor, now_ver, now_hor | (col1 << 1)));

        if (col && s[row][col] == e[row][col - 1] && !(now_hor & (col1 >> 1))) {
            if (!(prev_ver & col1) && (now_hor & col1))
                re = min(re, 1 + dfs(row, col + 1, prev_ver, prev_hor, now_ver, now_hor | (col1 >> 1)));
            else
                re = min(re, dfs(row, col + 1, prev_ver, prev_hor, now_ver, now_hor | (col1 >> 1)));
        }
        if (row < n - 1 && s[row][col] == e[row + 1][col])
            re = min(re, dfs(row, col + 1, prev_ver, prev_hor, now_ver | col1, now_hor));
        return re;
    }
}

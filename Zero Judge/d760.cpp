/*************************************************************************
  > File Name: d760.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Mar 30 21:55:20 2018
*************************************************************************/

#include <bits/stdc++.h>
#define inf 0x7ffffff
using namespace std;
const int start = 0;
int n, m, i, j, b, d, ans;
int lines[210][210];
int backtrace[210];
bool visit[210];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        memset(lines, 0, sizeof(lines));
        for (int i = 1; i <= n; i++)
            cin >> lines[(i << 1) - 1][i << 1];
        const int end = (n << 1) + 1;
        cin >> m;
        for (int k = 0; k < m; k++) {
            cin >> i >> j;
            cin >> lines[i << 1][(j << 1) - 1];
        }
        cin >> b >> d;
        for (int i = 0; i < b; i++) {
            cin >> j;
            lines[start][(j << 1) - 1] = inf;
        }
        for (int i = 0; i < d; i++) {
            cin >> j;
            lines[j << 1][end] = inf;
        }
        ans = 0;
        while (1) {
            bool flag = false;
            queue<int> que;
            int cur;
            memset(visit, 0, sizeof(visit));
            visit[0] = 1;
            que.push(start);
            while (!que.empty()) {
                cur = que.front();
                que.pop();
                if (cur == end) {
                    flag = true;
                    break;
                }
                for (int i = 1; i <= end; i++) {
                    if (lines[cur][i] > 0 && (!visit[i])) {
                        que.push(i);
                        visit[i] = 1;
                        backtrace[i] = cur;
                    }
                }
            }
            if (flag) {
                j = inf;
                i = end;
                while (i != start) {
                    j = min(j, lines[backtrace[i]][i]);
                    i = backtrace[i];
                }
                i = end;
                while (i != start) {
                    lines[backtrace[i]][i] -= j;
                    lines[i][backtrace[i]] += j;
                    i = backtrace[i];
                }
                ans += j;
            }
            else
                break;
        }
        cout << ans << '\n';
    }
}

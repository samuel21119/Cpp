/*************************************************************************
  > File Name: 00820 - Internet Bandwidth.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jun 29 10:50:32 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, s, t, c, cnt, ans;
int flow[101][101];
int backtrace[101];
int findmin(int a, int b) {
    if (a == s)
        return b;
    return findmin(backtrace[a], min(b, flow[backtrace[a]][a]));
}
void backt(int a, int b) {
    if (a == s)
        return;
    flow[a][backtrace[a]] += b;
    flow[backtrace[a]][a] -= b;
    backt(backtrace[a], b);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cnt = 1;
    while (cin >> n && n) {
        cin >> s >> t >> c;
        ans = 0;
        memset(flow, 0, sizeof(flow));
        for (int i = 0; i < c; i++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            flow[t1][t2] += t3;
            flow[t2][t1] += t3;
        }
        bool flag = 1;
        while (flag) {
            flag = 0;
            queue<int> que;
            que.push(s);
            memset(backtrace, false, sizeof(backtrace));
            backtrace[s] = s;
            while (!que.empty()) {
                int cur = que.front();
                que.pop();
                if (cur == t) {
                    int tmp = findmin(t, 0x7fffffff);
                    backt(t, tmp);
                    ans += tmp;
                    flag = 1;
                    break;
                }
                for (int i = 1; i <= n; i++) {
                    if (flow[cur][i] > 0 && !backtrace[i]) {
                        backtrace[i] = cur;
                        que.push(i);
                    }
                }
            }
        }
        cout << "Network " << cnt++ << "\nThe bandwidth is " << ans << ".\n\n";
    }
}

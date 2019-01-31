/*************************************************************************
  > File Name: 00753 - A Plug for UNIX.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jul 15 15:38:24 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
int line[410][410];
int n, m, k, ans, N, Minus;
int backtrace[410];

int trace_min(int n, int MIN) {
    if (!n)
        return MIN;
    return trace_min(backtrace[n], min(MIN, line[backtrace[n]][n]));
}
void trace_minus(int n) {
    if (!n)
        return;
    line[backtrace[n]][n] -= Minus;
    line[n][backtrace[n]] += Minus;
    trace_minus(backtrace[n]);
}
int max_flow() {
    ans = 0;
    for (bool flag = false; 1; flag = false) {
        queue<int> que;
        que.push(0);
        for (int i = 1; i <= N; i++)
            backtrace[i] = -1;
        while (!que.empty()) {
            int cur = que.front();
            if (cur == N) {
                 flag = true;
                 break;
            }
            que.pop();
            for (int i = 1; i <= N; i++) {
                if (line[cur][i] > 0 && backtrace[i] == -1) {
                    backtrace[i] = cur;
                    que.push(i);
                }
            }
        }
        if (!flag)
            return m - ans;
        Minus = trace_min(N, inf);
        trace_minus(N);
        ans += Minus;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    string tmp1, tmp2;
    string s;
    cin >> c;
    while (c--) {
        memset(line, 0, sizeof(line));
        cin >> n;
        map<string, int> plug;
        for (int i = 0; i < n; i++) {
            cin >> tmp1;
            if (plug.find(tmp1) == plug.end())
                plug[tmp1] = i + 1;
            line[0][plug[tmp1]] += 1;
        }
        cin >> m;
        N = 300 + m + 1;
        for (int i = 301; i < N; i++) {
            cin >> s >> tmp1;
            if (plug.find(tmp1) == plug.end())
                plug[tmp1] = ++n;
            line[plug[tmp1]][i] = 1;
            line[i][N] = 1;
        }
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> tmp1 >> tmp2;
            if (plug.find(tmp1) == plug.end())
                plug[tmp1] = ++n;
            if (plug.find(tmp2) == plug.end())
                plug[tmp2] = ++n;
            int a = plug[tmp1];
            int b = plug[tmp2];
            line[b][a] = inf;
        }
        cout << max_flow() << '\n';
        if (c)
            cout << '\n';
    }
    return 0;
}

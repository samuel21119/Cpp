/*************************************************************************
  > File Name: 11045 - My T-shirt suits me.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Apr  1 17:10:43 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int num(string i) {
    if (i == "XXL")
        return 1;
    if (i == "XL")
        return 2;
    if (i == "L")
        return 3;
    if (i == "M")
        return 4;
    if (i == "S")
        return 5;
    if (i == "XS")
        return 6;
    return 0;
}

int line[70][70];
bool visit[70];
int back_trace[70];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, m, Max, end;
    string s;
    cin >> c;
    while (c--) {
        cin >> n >> m;
        end = n + m + 1;
        Max = 0;
        memset(line, 0, sizeof(line));
        for (int i = 1; i <= m; i++) {
            line[0][i] = 1;
            for (int j = 0; j < 2; j++) {
                cin >> s;
                for (int k = num(s); k <= n; k += 6)
                    line[i][m + k] = 1;
            }
        }
        for (int i = m + 1; i < end; i++)
            line[i][end] = 1;
        bool flag = true;
        while (flag) {
            flag = false;
            queue<int> que;
            int cur;
            memset(visit, false, sizeof(visit));
            visit[0] = true;
            que.push(0);
            while (!que.empty() && !flag) {
                cur = que.front();
                que.pop();
                if (cur == end)
                    flag = true;
                else for (int i = 0; i <= end; i++) {
                    if ((!visit[i]) && line[cur][i]) {
                        back_trace[i] = cur;
                        visit[i] = true;
                        que.push(i);
                    }
                }
            }
            if (flag) {
                for (int i = end; i != 0; i = back_trace[i]) {
                    line[back_trace[i]][i]--;
                    line[i][back_trace[i]]++;
                }
                Max++;
            }
        }
        cout << (Max == m ? "YES\n" : "NO\n");
    }
    return 0;
}

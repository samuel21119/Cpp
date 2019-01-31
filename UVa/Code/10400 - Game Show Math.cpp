/*************************************************************************
  > File Name: 10400 - Game Show Math.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Oct 25 17:56:10 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, in[110], target;
int out[110];
char change[] = {'+', '-', '*', '/'};
inline bool range(int i) {
    return -32000 > i || i > 32000;
}
bool visit[110][70000];
bool dfs(int index, int now) {
    if (range(now))
        return 0;
    if (visit[index][now])
        return 0;
    visit[index][now] = 1;
    if (index == n)
        return now == target;

    out[index] = 0;
    if (dfs(index + 1, now + in[index]))
        return 1;

    out[index] = 1;
    if (dfs(index + 1, now - in[index]))
        return 1;

    out[index] = 2;
    if (dfs(index + 1, now * in[index]))
        return 1;

    if (now % in[index])
        return 0;
    out[index] = 3;
    if (dfs(index + 1, now / in[index]))
        return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        cin >> target;
        memset(visit, 0, sizeof(bool) * 110 * 70000);
        if (dfs(1, in[0])) {
            cout << in[0];
            for (int i = 1; i < n; i++)
                cout << change[out[i]] << in[i];
            cout << '=' << target;
        }else
            cout << "NO EXPRESSION";
        cout << '\n';
    }
    return 0;
}

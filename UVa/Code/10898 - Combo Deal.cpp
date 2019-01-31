/*************************************************************************
  > File Name: 10898 - Combo Deal.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep  9 10:52:53 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
struct combo {
    int cnt[6];
    int price;
}order[10];
int in[6];
map<int, int> dp;
int n, m, q, s, a;
int dfs(int state) {
    if (!state)
        return 0;
    if (dp.find(state) != dp.end())
        return dp[state];
    int &now = dp[state];
    now = inf;
    vector<int> sep;
    sep.resize(n);
    for (int i = n - 1; i >= 0; i--, state /= 10)
        sep[i] = state % 10;
    for (int i = 0; i < m; i++) {
        int j;
        for (j = 0; j < n; j++)
            if (sep[j] < order[i].cnt[j])
                break;
        if (j < n)
            continue;
        int next = 0;
        for (j = 0; j < n; j++)
            next = next * 10 + sep[j] - order[i].cnt[j];
        now = min(now, dfs(next) + order[i].price);
    }
    for (int i = 0; i < n; i++) {
        if (!sep[i])
            continue;
        int next = 0;
        for (int j = 0; j < n; j++)
            next = next * 10 + sep[j] - (i == j);
        now = min(now, dfs(next) + in[i]);
    }
    return now;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> in[i];
        cin >> m;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cin >> order[i].cnt[j];
            cin >> order[i].price;
        }
        dp.clear();
        cin >> q;
        while (q--) {
            s = 0;
            for (int i = 0; i < n; i++) {
                cin >> a;
                s = s * 10 + a;
            }
            cout << dfs(s) << '\n';
        }
    }
    return 0;
}

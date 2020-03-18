/*************************************************************************
  > File Name: 1908.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar 18 11:20:28 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[25][25];
int dp[2][1 << 22];
int ans;
int vaild_state[50000], cnt;
set<int> s;
string to2(int i) {
    string re;
    for (int a = 0; a < n; a++) {
        if (i & 1)
            re += '1';
        else
            re += '0';
        i >>= 1;
    }
    return re;
}
int get_safe(int state) {
    int safe = (1 << n) - 1 - state;
    for (int j = 0, k = 1; j < n; j++, k <<= 1) {
        int a = j - 1, b = j + 1;
        bool flip = 0;
        if (a >= 0)
            flip |= (1 << a) & state;
        if (b <= n)
            flip |= (1 << b) & state;
        if (flip && (safe & k))
           safe ^= k;
    }
    return safe;
}
void vaild(int ind, int state) {
    if (ind == n + 1) {
        vaild_state[cnt++] = state;
        int safe = get_safe(state);
        s.insert(safe);
        return;
    }
    if (state & 1)
        vaild(ind + 1, state << 1);
    else {
        vaild(ind + 1, (state << 1) | 1);
        vaild(ind + 1, state << 1);
    }
}
void dfs(int ind, int sum, int state, int i) {
    if (ind == n + 1) {
        int now = i & 1;
        int pre = !now;
        int safe = get_safe(state);
        dp[now][safe] = max(dp[now][safe], dp[pre][state] + sum);
        ans = max(ans, dp[now][safe]);
        return;
    }
    if (state & 1)
        dfs(ind + 1, sum, state << 1, i);
    else {
        dfs(ind + 1, sum + in[i][ind], (state << 1) | 1, i);
        dfs(ind + 1, sum, state << 1, i);
    }
}
map<int, vector<int>> mx;
inline void pre_calc() {
    sort(vaild_state, vaild_state + cnt);
    for (int i : s) {
        for (int j = 0; j < cnt; j++)
            if ((vaild_state[j] & i) == vaild_state[j]) {
                mx[i].emplace_back(vaild_state[j]);
            };
    }
}
inline void get_mx(int x) {
    for (int i : s) {
        for (int j : mx[i])
            dp[x][j] = max(dp[x][j], dp[x][i]);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vaild(1, 0);
    pre_calc();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> in[i][j];
    for (int i = 1; i <= n; i++) {
        memset(dp[i & 1], 0, sizeof(dp[0]));
        dfs(1, 0, 0, i);
        get_mx(i & 1);
    }
    cout << ans << '\n';
    return 0;
}

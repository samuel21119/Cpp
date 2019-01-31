/*************************************************************************
  > File Name: 00307 - Sticks.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jun 29 12:16:42 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int sticks[100];
bool use[100];
int len, sum;
bool cmp(int a, int b) {
    return a > b;
}
bool dfs(int i, int l, int r) {
    if (!l) {
        r -= len;
        if (!r)
            return true;
        for (i = 0; i < n && use[i]; i++);
        use[i] = 1;
        if (dfs(i, len - sticks[i], r)) return true;
        use[i] = 0;
        return false;
    }
    while (++i < n) {
        if (i && sticks[i - 1] == sticks[i] && !use[i - 1]) continue;
        if (sticks[i] > l || use[i]) continue;
        use[i] = 1;
        if (dfs(i, l - sticks[i], r)) return true;
        use[i] = 0;
        if (sticks[i] == l)
            break;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        sum = 0;
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            cin >> sticks[i];
            sum += sticks[i];
        }
        memset(use, false, sizeof(use));
        sort(sticks, sticks + n, cmp);
        for (len = sticks[0]; len <= sum / 2 && flag; len++) {
            if (sum % len)
                continue;
            if (dfs(-1, len, sum)) flag = 0;
        }
        cout << (flag ? sum : len - 1) << '\n';
    }
    return 0;
}

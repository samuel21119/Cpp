/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 24 13:25:01 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int in[4][1000010];
int parse[1000010];
int cnt(int x) {
    int re = 0;
    while (x) {
        re += x & 1;
        x >>= 1;
    }
    return re;
}
int lim;
int dp[1000010][8];
vector<int> state[8];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if (min(n, m) >= 4) {
        cout << -1;
        return 0;
    }
    if (min(n, m) == 1) {
        cout << 0;
        return 0;
    }
    if (n <= m) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                char a;
                cin >> a;
                in[i][j] = a - '0';
            }
    }else {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                char a;
                cin >> a;
                in[j][i] = a - '0';
            }
        swap(n, m);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            parse[i] = (parse[i] << 1) | in[j][i];
    }

    lim = 1 << n;
    for (int i = 0; i < lim; i++) {
        for (int j = i + 1; j < lim; j++) {
            int x = i ^ j;
            bool add = 1;
            for (int k = 1; k < n; k++) {
                add &= ((x >> 1) & 1) ^ (x & 1);
                x >>= 1;
            }
            if (add) {
                state[j].emplace_back(i);
                state[i].emplace_back(j);
            }
        }
        //cout << i << ": ";
        //for (int j : state[i])
            //cout << j << ' ';
        //cout << endl;
    }
    for (int i = 0; i < lim; i++)
        dp[1][i] = cnt(parse[1] ^ i);
    for (int i = 2; i <= m; i++) {
        fill(dp[i], dp[i] + lim, 1e9);
        for (int st = 0; st < lim; st++) {
            int add = cnt(parse[i] ^ st);
            for (int j : state[st])
                dp[i][st] = min(dp[i][st], dp[i - 1][j] + add);
        }
    }
    cout << *min_element(dp[m], dp[m] + lim) << '\n';
    return 0;
}

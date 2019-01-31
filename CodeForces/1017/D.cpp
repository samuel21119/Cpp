/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Aug  8 22:53:59 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int cnt[1 << 13];
int ans[1 << 13][101];
int cost[13];
int to2(long long a) {
    int mul = 1;
    int ans = 0;
    while (a) {
        ans += mul * (a & 1);
        a /= 10;
        mul *= 2;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    long long a, b;
    cin >> n >> m >> q;
    for (int i = n - 1; i >= 0; i--)
        cin >> cost[i];
    for (int i = 0; i < m; i++) {
        cin >> a;
        cnt[to2(a)]++;
    }
    int MAX = 1 << n;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (!cnt[j])
                continue;
            int tmp = i ^ j;
            int sum = 0;
            for (int k = 0; k < n; k++) {
                if (!(tmp & (1 << k)))
                    sum += cost[k];
            }
            if (sum > 100)
                continue;
            ans[i][sum] += cnt[j];
        }
        for (int j = 1; j <= 100; j++)
            ans[i][j] += ans[i][j - 1];
    }
    while (q--) {
        cin >> a >> b;
        cout << ans[to2(a)][b] << '\n';
    }
    return 0;
}

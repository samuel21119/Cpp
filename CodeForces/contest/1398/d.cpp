/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 14 23:12:10 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n[3];
ll in[3][2010];
ll ans;
ll save[201][201][201];
ll dp(int r, int g, int b) {
    ll re = 0;
    if (r < 0 || g < 0 || b < 0)
        return 0;
    if (save[r][g][b])
        return save[r][g][b];
    re = max(re, dp(r - 1, g - 1, b) + in[0][r] * in[1][g]);
    re = max(re, dp(r, g - 1, b - 1) + in[1][g] * in[2][b]);
    re = max(re, dp(r - 1, g, b - 1) + in[0][r] * in[2][b]);
    save[r][g][b] = re;
    return re;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n[0] >> n[1] >> n[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n[i]; j++)
            cin >> in[i][j];
        sort(in[i] + 1, in[i] + n[i] + 1);
    }
    cout << dp(n[0], n[1], n[2]);
    return 0;
}

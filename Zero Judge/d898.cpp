/*************************************************************************
  > File Name: d898.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep 23 09:46:23 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int dp[15][15][15];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1][1][1] = 1;
    for (int i = 2; i <= 13; i++)
        for (int a = 1; a <= i; a++)
            for (int b = 1; b <= i; b++) {
                dp[i][a + 1][b] += dp[i - 1][a][b];
                dp[i][a][b + 1] += dp[i - 1][a][b];
                dp[i][a][b] += dp[i - 1][a][b] * (i - 2);
            }
    int c, n, a, b;
    cin >> c;
    while (c--) {
        cin >> n >> a >> b;
        cout << dp[n][a][b] << '\n';
    }
    return 0;
}

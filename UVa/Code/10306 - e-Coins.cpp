/*************************************************************************
  > File Name: 10306 - e-Coins.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Feb  1 22:55:31 2018
*************************************************************************/

#include <iostream>
#include <cstring>
#include <cmath>
#define inf 0x7fffffff
using namespace std;

int dp[301][301]; //First: C ; Second: I
int C[41], I[41];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, m, s, ans;
    cin >> c;
    while (c--) {
        cin >> m >> s;
        for (int i = 0; i < m; i++)
            cin >> C[i] >> I[i];
        memset(dp, -1, sizeof(dp));
        ans = inf;
        dp[0][0] = 0;
        for (int i = 0; i < m; i++)
            for (int j = C[i]; j <= s; j++) 
                for (int k = I[i]; k <= s; k++)
                    if (dp[j - C[i]][k - I[i]] != -1) {
                        if (dp[j][k] == -1)
                            dp[j][k] = dp[j - C[i]][k - I[i]] + 1;
                        else
                            dp[j][k] = min(dp[j][k], dp[j - C[i]][k - I[i]] + 1);
                    }
        for (int i = 0; i <= s; i++) {
            int j = sqrt(s * s - i * i);
            if (i * i + j * j != s * s)
                continue;
            if (dp[i][j] != -1)
                ans = min(ans, dp[i][j]);
        }
        if (ans == inf)
            cout << "not possible\n";
        else
            cout << ans << '\n';
    }
}

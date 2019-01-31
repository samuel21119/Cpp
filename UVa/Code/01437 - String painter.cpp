/*************************************************************************
  > File Name: 1437 - String painter.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar  7 22:09:55 2018
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int dp[101][101];
int ans[101];
char a[101], b[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> a >> b) {
        int len = (int)strlen(a);
        for (int i = 0; i < len; i++)
            dp[i][i] = 1;
        for (int j = 1; j < len; j++)
            for (int i = 0; i + j < len; i++) {
                int r = i + j;
                dp[i][r] = dp[i][i] + dp[i + 1][r];
                for (int k = i + 1; k <= r; k++)
                    if (b[i] == b[k])
                        dp[i][r] = min(dp[i][r], dp[i + 1][k] + dp[k + 1][r]);
            }
        ans[0] = a[0] != b[0];
        for (int i = 1; i < len; i++) {
            if (a[i] == b[i]) {
                ans[i] = ans[i - 1];
                continue;
            }
            ans[i] = dp[0][i];
            for (int j = 0; j < i; j++)
                ans[i] = min(ans[i], ans[j] + dp[j + 1][i]);
        }
        cout << ans[len - 1] << '\n';
    }
}

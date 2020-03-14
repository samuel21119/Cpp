/*************************************************************************
  > File Name: ee.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 10 14:50:59 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[500];
int dp[500][501];
int ans[500];
int came[500][501];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    ans[0] = dp[0][0] = 1;
    came[0][0] = 0;
    for (int i = 1; i < n; i++) {
        ans[i] = dp[i][0] = ans[i - 1] + 1;
        came[i][0] = i;
        for (int j = i - 1, sh = 0; j >= 0; j--, sh++) {
            int now = in[i];
            int pre = in[j];
            int t = now + sh;
            if (t < pre)
                break;
            if (dp[j][t - pre])  {
                dp[i][sh + 1] = dp[j][t - pre];
                j = came[j][t - pre];
                came[i][sh + 1] = j;
            }else
                break;
            ans[i] = min(ans[i], dp[i][sh + 1]);
        }
    }
    cout << ans[n - 1] << '\n';
    return 0;
}

/*************************************************************************
  > File Name: C.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed May 30 16:42:18 2018
*************************************************************************/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int fonts[3005];
ll dp[3005][3];
ll ans;
const ll MAX = 1LL << 62;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> fonts[i];
    for (int i = 0; i < n; i++)
        for (int j = 1; j < 3; j++)
            dp[i][j] = MAX;
    for (int i = 0; i < n; i++)
        cin >> dp[i][0];
    ans = MAX;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (fonts[i] >= fonts[j])
                continue;
            dp[j][1] = min(dp[i][0] + dp[j][0], dp[j][1]);
            if (dp[i][1] < MAX)
                ans = min(dp[j][2] = min(dp[i][1] + dp[j][0], dp[j][2]), ans);
        }
    if (ans == MAX)
        ans = -1;
    cout << ans << '\n';
    return 0;
}

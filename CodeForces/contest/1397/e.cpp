/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Sep  1 11:50:12 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
ll r1, r2, r3, d;
ll in[1000010];
ll dp[1000010][2];
ll A[1000010], B[1000010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
    }
    for (int i = 1; i <= n; i++) {
        A[i] = r1 * in[i] + r3;
        B[i] = min((in[i] + 1) * r1, r2) + r1;
        dp[i][0] = min(dp[i - 1][0] + A[i], dp[i - 1][1] + min(A[i], B[i]) + 2 * d);
        dp[i][1] = dp[i - 1][0] + B[i];
    }
    ll ans = min(dp[n][0], dp[n][1] + 2 * d);
    ll sum = min(A[n], B[n] + d);
    for (int i = n - 1; i; i--) {
        sum += B[i] + d;
        ans = min(ans, sum + dp[i - 1][0]);
    }
    cout << ans + (n - 1) * d << '\n';
    return 0;
}

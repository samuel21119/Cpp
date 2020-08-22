#include <bits/stdc++.h>
using namespace std;

int dp[4010][4010];
int n;
int x[4010], y[4010];
const int inf = 1e9;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    
    fill(dp[1], dp[1] + 4010, inf);
    dp[1][1] = min(x[1], y[1]);
    
    for (int i = 2; i <= n; i++) {
        fill(dp[i], dp[i] + 4010, inf);
        for (int j = 0; j < i; j++) {
            int cur = dp[i - 1][j];
            if (cur == inf)
                continue;
            if (cur <= x[i] * (i - 1))
                dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + x[i]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + x[i]);
        }
        for (int j = 0; j < i; j++) {
            int cur = dp[i - 1][j];
            if (cur == inf)
                continue;
            if (cur <= y[i] * (i - 1))
                dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + y[i]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + y[i]);
        }
    }
    int ans = 0;
    for (int i = n; i >= 0; i--) {
        if (dp[n][i] != inf) {
            ans = i;
            break;
        }
    }
    cout << n - ans << '\n';
    return 0;
}
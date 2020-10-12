#include <bits/stdc++.h>
using namespace std;

int n, r;
pair<int, int> xy[100010];
int t[100010];
int mx, ptr;
int dp[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> t[i] >> a >> b;
        xy[i] = {a, b};
    }
    r *= 2;
    mx = -100000;
    xy[0] = {1, 1};
    for (int i = 1; i <= n; i++) {
        if (abs(xy[i].first - 1) + abs(xy[i].second - 1) > t[i])
            continue;
        while (t[ptr] + r < t[i])
            mx = max(mx, dp[ptr++]);
        if (ptr != 0)
            dp[i] = mx + 1;
        for (int j = ptr; j < i; j++)
            if (abs(xy[i].first - xy[j].first) + abs(xy[i].second - xy[j].second) <= t[i] - t[j])
                dp[i] = max(dp[i], dp[j] + 1);
        cout << dp[i] << '\n';
    }
    cout << *max_element(dp, dp + n + 1) << '\n';
}
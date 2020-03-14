#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[2][1 << 7];
int n, p, aud;
ll in[100010];
vector<int> s[100010];
int all;
int calc(int i) {
    int re = 0;
    while (i) {
        re += i & 1;
        i >>= 1;
    }
    return re;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> aud;
    all = 1 << p;
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    for (int i = 1; i <= n; i++) {
        s[i].resize(p + 1);
        s[i][0] = in[i];
        for (int j = 1; j <= p; j++)
            cin >> s[i][j];
    }
    sort(s + 1, s + n + 1, [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
            });
    for (int i = 1; i <= n; i++) {
        int now = i & 1;
        int prev = !now;
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 0; j < all; j++) {
            dp[now][j] = max(dp[prev][j] + (p - calc(j) + aud <= n - i ? 0 : s[i][0]), dp[now][j]);
            for (int k = 1, bit = 1; k <= p; k++, bit <<= 1) {
                if ((j & bit) == 0) {
                    dp[now][j | bit] = max(dp[prev][j] + s[i][k], dp[now][j | bit]);
                }
            }
        }
    }
    cout << dp[n & 1][all - 1] << '\n';
    return 0;
}

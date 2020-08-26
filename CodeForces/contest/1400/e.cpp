/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Aug 26 01:01:58 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000;
const int inf = 1 << 30;
int n;
int dp[5010];
int pre[5010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(pre, pre + maxn + 1, inf);
    pre[0] = 0;
    while (n--) {
        int now;
        cin >> now;

        fill(dp, dp + maxn + 1, inf);
        int mn = inf;
        for (int i = 0; i <= min(maxn, now); i++) {
            mn = min(mn, pre[i] - i);
            dp[i] = min(pre[i], mn + i) + (i != now);
        }

        pre[maxn] = dp[maxn];
        for (int i = maxn - 1; i >= 0; i--)
            pre[i] = min(pre[i + 1], dp[i]);
    }
    cout << *min_element(dp, dp + 5001) << '\n';
    return 0;
}

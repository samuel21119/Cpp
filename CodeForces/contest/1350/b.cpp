/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun May 17 20:12:39 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[100010];
int dp[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            cin >> in[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i * 2; j <= n; j += i)
                if (in[i] < in[j])
                    dp[j] = max(dp[j], dp[i] + 1);
        }
        cout << *max_element(dp + 1, dp + n + 1) << '\n';
    }
    return 0;
}

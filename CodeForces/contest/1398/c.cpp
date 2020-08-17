/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 14 22:48:49 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
int in[100010];
int sum[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        map<int, int> m;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            char a;
            cin >> a;
            in[i] = a - '0';
            sum[i] = sum[i - 1] + in[i];
        }
        for (int i = 0; i <= n; i++) {
            ans += m[sum[i] - i];
            m[sum[i] - i]++;
        }
        cout << ans << '\n';
    }
    return 0;
}

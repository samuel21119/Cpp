/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep 10 14:37:41 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
ll in[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = 0;
        ll x = 0;
        ll y = 0;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        for (int i = n - 1; i; i--) {
            if (in[i] > 0) {
                ll tmp = min(y, in[i]);
                in[i] -= tmp;
                y -= tmp;
                ans += in[i];
                x += in[i];
            }else {
                y -= in[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

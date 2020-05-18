/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Apr 12 22:20:13 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll in[100010];
int cnt(ll x) {
    int c = 0;
    while (x) {
        c++;
        x >>= 1;
    }
    return c;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            ll &now = in[i];
            ll &pre = in[i - 1];
            if (now >= pre)
                continue;
            ll dx = pre - now;
            ll c = cnt(dx);
            ans = max(ans, c);
            now = pre;
        }
        cout << ans << '\n';
    }
    return 0;
}

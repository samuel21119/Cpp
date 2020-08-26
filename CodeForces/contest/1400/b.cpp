/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Aug 25 22:40:31 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll p, f;
ll x, y;
ll s, w;
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> p >> f >> x >> y >> s >> w;
        if (s > w) {
            swap(x, y);
            swap(s, w);
        }
        // p
        for (int i = 0; i <= x; i++) {
            if (i * s > p)
                break;
            ll a = i;
            ll b = min((p - i * s) / w, y);
            ll ra = x - i;
            ll rb = y - b;
            ll cnt = min(f / s, ra);
            ll tmp = cnt + min(max((f - cnt * s) / w, 0LL), rb);
            ans = max(ans, tmp + a + b);
        }
        cout << ans << '\n';
    }
    return 0;
}

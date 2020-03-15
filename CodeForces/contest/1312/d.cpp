/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 10 15:02:26 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;

int n, m;
ll ans;
ll two[200010];
ll poww(int t, ll i) {
    if (i == 0)
        return 1;
    if (i == 1) 
        return t;
    ll tt = poww(t, i / 2) % mod;
    return tt * tt % mod * (i & 1 ? t : 1) % mod;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if (n == 2) {
        cout << "0\n";
        return 0;
    }
    two[0] = 1; // 2^(n-3)
    for (int i = 1; i <= n; i++)
        two[i] = two[i - 1] * 2 % mod;
    ll c = 1;
    ll cnt = 1;
    for (int i = n - 1; i <= m; i++) { // C(i - 1, n - 2)
        ans = (ans + c) % mod;
        //cout << ans << ' ' << c << endl;
        c = c * i % mod * poww(cnt++, mod - 2) % mod;
    }
    cout << ans * (n - 2) % mod * two[n - 3] % mod;
    return 0;
}

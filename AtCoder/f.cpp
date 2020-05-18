/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Apr  4 22:42:40 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int check(ll n, ll i) {
    while (n % i == 0)
        n /= i;
    return n % i == 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, n1;
    cin >> n;
    n1 = n - 1;
    ll ans = 0;
    for (ll i = 1; i * i <= n1; i++) {
        if (n1 % i == 0) {
            if (i > 1)
                ans++;
            if (n1 / i != i)
                ans++;
        }
    }
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i > 1)
                ans += check(n, i);
            if (n / i != i)
                ans += check(n, n / i);
        }
    }
    cout << ans << '\n';
    return 0;
}

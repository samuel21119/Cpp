/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 21 06:21:00 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 1;
    for (ll i = n / 2 + 1; i <= n; i++)
        ans *= i;
    for (int i = 2; i <= n / 2; i++)
        ans /= i;
    ans /= 2;
    for (ll i = 2; i < n / 2; i++)
        ans *= i;
    for (ll i = 2; i < n / 2; i++)
        ans *= i;
    cout << ans << '\n';
    return 0;
}

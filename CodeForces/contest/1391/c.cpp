/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 24 13:17:57 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll ans = 1, two = 1;
    for (int i = 2; i <= n; i++)
        ans = ans * i % mod;
    for (int i = 1; i < n; i++)
        two = two * 2 % mod;
    cout << (ans + mod - two) % mod;
    return 0;
}

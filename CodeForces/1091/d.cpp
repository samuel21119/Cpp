/*************************************************************************
  > File Name: dd.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Dec 31 01:05:44 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans[1000010];
ll p;
ll mod = 998244353;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 9;
    int n;
    cin >> n;
    p = 6;
    for (ll i = 4; i <= n; i++) {
        ll tmp = ans[i - 1];
        tmp = (tmp + p - 1) % mod;
        ans[i] = tmp * i % mod;
        p = p * i % mod;
    }
    cout << ans[n];
    return 0;
}

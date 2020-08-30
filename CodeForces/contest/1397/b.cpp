/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Aug 30 22:42:35 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
ll in[100010];
ll mypow(ll x, int cnt) {
    if (cnt == 1)
        return x;
    if (cnt == 0)
        return 1;
    ll tmp = mypow(x, cnt / 2);
    tmp *= tmp;
    if (cnt & 1)
        tmp *= x;
    return tmp;
    
}
bool check(ll x) {
    double l = n * log10(x);
    return l <= 15;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in, in + n);
    ll ans = 1LL << 60;
    for (ll i = 1; check(i); i++) {
        ll tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += abs(in[j] - mypow(i, j));
        }
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}

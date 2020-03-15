/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Feb  4 20:22:40 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k, a, b;
ll in[100010];
ll calc(ll l, ll r, ll cnt, int lp, int rp) {
    if (!cnt)
        return a;
    if (l == r)
        return b * cnt;
    ll re = (r - l + 1) * cnt * b;
    int cl = lower_bound(in + lp, in + rp, l) - in;
    int cr = upper_bound(in + lp, in + rp, (l + r) / 2) - in;
    int cntl = cr - cl;

    return min(re, calc(l, (l + r) / 2, cntl, lp, cr) + calc((l + r) / 2 + 1, r, cnt - cntl, cr, rp));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a >> b;
    for (int i = 0; i < k; i++)
        cin >> in[i];
    sort(in, in + k);
    cout << calc(1, 1 << n, k, 0, k) << '\n';
    return 0;
}

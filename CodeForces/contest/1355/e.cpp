/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon May 25 18:11:18 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, r, m;
int n;
ll in[100010];
ll sum[100010];

ll calc(ll h) {
    ll re = 0;
    int lower = lower_bound(in, in + n, h) - in - 1;
    int upper = upper_bound(in, in + n, h) - in;
    ll Lsum, Usum;
    if (lower < 0)
        Lsum = 0;
    else
        Lsum = h * (lower + 1) - sum[lower];
    if (upper == n)
        Usum = 0;
    else {
        Usum = sum[n - 1] - sum[upper] + in[upper] - h * (n - upper);
    }
    ll mn = min(Lsum, Usum);
    re += mn * m;
    Lsum -= mn, Usum -= mn;
    re += Lsum * a + Usum * r;
    return re;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> r >> m;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    m = min(m, a + r);
    sort(in, in + n);
    ll l = in[0];
    ll r = in[n - 1];
    sum[0] = in[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + in[i];

    while (l + 1e6 < r) {
        int ml = (l * 2 + r) / 3;
        int mr = (l + r * 2) / 3;
        
        if (calc(ml) > calc(mr))
            l = ml;
        else
            r = mr;
        //cout << l << ' ' << r << endl;
    }

    ll ans = 1LL << 60;
    for (int i = l; i <= r; i++)
        ans = min(ans, calc(i));
    cout << ans << '\n';

    return 0;
}

/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Aug 13 07:02:09 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, d, m;
int in[100010];
ll sum[100010], sum2[100010];
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> m;
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    sort(in + 1, in + n + 1);
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++) {
        if (in[i] <= m) {
            v1.emplace_back(in[i]);
            sum[i] = sum[i - 1] + in[i];
        }
        else
            v2.emplace_back(in[i]);
    }
    int sz1 = v1.size();
    ll all = sum[sz1];
    int sz2 = v2.size();
    if (sz2 <= 1) {
        cout << sum[sz1] + (sz2 == 0 ? 0 : in[n]) << '\n';
        return 0;
    }
    reverse(v2.begin(), v2.end());
    for (int i = 1; i <= sz2; i++)
        sum2[i] = sum2[i - 1] + v2[i - 1];

    for (int i = 1; i <= sz2; i++) {
        ll cantspeak = (i - 1) * d;
        ll left = n - i;
        ll tmp = sum2[i];
        if (left < cantspeak)
            break;
        cantspeak = max(0LL, cantspeak - (sz2 - i));
        if (cantspeak < sz1)
            tmp += all - sum[cantspeak];
        //cout << tmp << '\n';
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}

/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Feb  5 22:02:59 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, m;
ll in[100010];
ll sum;
double mx;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        sum += in[i];
    }
    sort(in, in + n);
    for (ll i = 0; i <= min(m, n - 1); i++) {
        mx = max(mx, double(sum + min((n - i) * k, m - i)) / (n - i));
        sum -= in[i];
    }
    cout << fixed << setprecision(7) << mx << '\n';
    return 0;
}

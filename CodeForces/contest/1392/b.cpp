/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 17 18:05:51 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
ll in[200010], k;
void d() {
    ll mx = *max_element(in, in + n);
    for (int i = 0; i < n; i++) {
        in[i] = mx - in[i];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        d();
        if (k % 2 == 0)
            d();
        for (int i = 0; i < n; i++)
            cout << in[i] << ' ';
        cout << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Feb 14 11:21:30 2020
*************************************************************************/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        if (m == 0) {
            cout << "0\n";
            continue;
        }
        ll d = n - m;
        m++;
        ll t1 = d % m;
        ll t2 = m - t1;
        ll t3 = (n - m + 1) / m;

        cout << (n * (n + 1) / 2 - t2 * t3 * (t3 + 1) / 2) - t1 * (t3 + 1) * (t3 + 2) / 2 << '\n';
    }
    return 0;
}

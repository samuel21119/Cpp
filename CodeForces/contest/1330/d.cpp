/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Apr  3 23:45:14 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll d, m;
ll ans[40];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ans[0] = 1;
    int t;
    cin >> t;
    while (t--) {
        cin >> d >> m;
        if (d == 1) {
            cout << 1 % m << '\n';
            continue;
        }
        for (ll i = 2, cnt = 1; i <= d; i <<= 1, cnt++) {
            ll next = i << 1;
            if (next <= d) {
                ans[cnt] = (ans[cnt - 1] * (next - i + 1) + next - i) % m;
            }else
                cout << (ans[cnt - 1] * (d - i + 1 + 1) + d - i + 1) % m << '\n';
        }
    }
    return 0;
}

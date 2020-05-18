/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun May 17 19:15:14 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll a;
        for (a = 2; a <= n; a++) {
            if (n % a == 0)
                break;
        }
        n += a;
        n += (k - 1) * 2;
        cout << n << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon May 25 17:41:00 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c, d;
ll ans;
ll calc(ll a1, ll d, ll n) {
    return (a1 * 2 + (n - 1) * d) * n / 2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d;
    for (int i = c; i <= d; i++) {
        int cur = i + 1;
        int mnX = cur - c;
        if (mnX > b)
            continue;
        int yn, xn;
        yn = c - b + 1;
        if (mnX < a) {
            ll X = a - mnX + 1;
            if (yn <= X) {
                ans += ll(b - a + 1) * yn;
                continue;
            }
            ans += X * (b - a + 1);
            yn -= X;
            mnX = a + 1;
        }
        xn = b - mnX + 1;
        if (xn <= yn) {
            ans += calc(xn, -1, xn);
        }else if (xn > yn) {
            ans += calc(xn, -1, yn); 
        }
    }
    cout << ans << '\n';
    return 0;
}

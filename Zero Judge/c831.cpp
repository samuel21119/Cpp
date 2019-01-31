/*************************************************************************
  > File Name: c831.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri 09 Nov 2018 07:17:19 AM PST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x1, x2, y1, y2;
    cin >> a >> b >> c >> d;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x = abs(a - c);
    ll y = abs(b - d);
    ll xx = abs(x1 - x2);
    xx = min(xx, x - xx);
    ll yy = abs(y1 - y2);
    yy = min(yy, y - yy);
    cout << xx + yy;
    return 0;
}

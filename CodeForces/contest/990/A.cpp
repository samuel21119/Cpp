/*************************************************************************
  > File Name: A.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jun 10 18:09:37 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c, d;
    long long tmp, ans;
    cin >> a >> b >> c >> d;
    ans = 1LL << 60;
    tmp = a % b;
    ans = min(ans, tmp * d);
    ans = min(ans, (b - tmp) * c);
    cout << ans << '\n';
    return 0;
}

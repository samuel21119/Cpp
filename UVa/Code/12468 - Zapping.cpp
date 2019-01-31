/*************************************************************************
  > File Name: 12468 - Zapping.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 27 12:34:00 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, ans;
    while (cin >> a >> b) {
        if (!(~a || ~b))
            break;
        ans = abs(a - b);
        ans = min(ans, 100 - ans);
        cout << ans << '\n';
    }
    return 0;
}

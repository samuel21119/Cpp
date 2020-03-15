/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Aug 11 21:31:26 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    while (k--) {
        int x1, y1, x2, y2;
        int ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            cout << abs(y1 - y2) << '\n';
            continue;
        }
        if (y1 < a)
            ans += a - y1, y1 = a;
        else if (b < y1)
            ans += y1 - b, y1 = b;
        if (y2 < a)
            ans += a - y2, y2 = a;
        else if (b < y2)
            ans += y2 - b, y2 = b;

        ans += abs(x1 - x2) + abs(y1 - y2);
        cout << ans << '\n';
    }
    return 0;
}

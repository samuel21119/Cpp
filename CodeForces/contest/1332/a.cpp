/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 31 21:34:46 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        int dx = b - a;
        int dy = d - c;
        bool t1 = (a + b == 0) || (x2 - x1 > 0);
        bool t2 = (c + d == 0) || (y2 - y1 > 0);
        if (t1 && t2 && x1 <= x + dx && x + dx <= x2 && y1 <= y + dy && y + dy <= y2)
            cout << "Yes";
        else
            cout << "No";
        cout << '\n';
    }
    return 0;
}

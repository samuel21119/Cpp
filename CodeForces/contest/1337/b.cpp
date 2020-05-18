/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Apr 15 22:39:29 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, n, m;
        cin >> x >> n >> m;
        while (n--) {
            int y = x;
            y /= 2;
            y += 10;
            if (y >= x) {
                break;
            }
            x = y;
        }
        while (m--)
            x -= 10;
        if (x <= 0)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
    return 0;
}

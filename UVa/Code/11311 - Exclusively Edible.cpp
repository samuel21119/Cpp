/*************************************************************************
  > File Name: 11311 - Exclusively Edible.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Jan 31 10:34:40 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y;
int a, b, c, d;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        a = n - x - 1;
        b = m - y - 1;
        c = x;
        d = y;
        cout << (a ^ b ^ c ^ d ? "Gretel" : "Hansel") << '\n';
    }
    return 0;
}

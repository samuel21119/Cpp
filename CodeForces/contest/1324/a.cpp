/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 12 21:04:11 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int a, b, x;
        a = b = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            a |= x % 2 == 1;
            b |= x % 2 == 0;
        }
        cout << (a ^ b ? "YES" : "NO") << '\n';
    }
    return 0;
}

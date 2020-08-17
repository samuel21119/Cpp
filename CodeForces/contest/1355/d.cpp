/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon May 25 18:06:17 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (n * 2 <= k) {
        cout << "YES\n";
        for (int i = 1; i < n; i++) {
            cout << "2 ";
            k -= 2;
        }
        cout << k << '\n';
        cout << "1\n";
    }else
        cout << "NO\n";
    return 0;
}

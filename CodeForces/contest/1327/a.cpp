/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Mar 23 22:31:42 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n % 2 != k % 2 || n < k) {
            cout << "NO\n";
            continue;
        }
        int a = n - k;
        a /= 2;
        if (a * 2 >= (k - 1) * k) {
            cout << "YES";
        }else
            cout << "NO";
        cout << '\n';
    }
    return 0;
}

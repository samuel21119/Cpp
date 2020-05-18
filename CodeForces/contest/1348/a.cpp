/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue May  5 20:56:26 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n = n / 2 + 1;
        int a = 1 << n;
        cout << a - 2 << '\n';
    }
    return 0;
}

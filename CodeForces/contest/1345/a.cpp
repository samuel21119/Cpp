/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed May  6 22:29:18 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if (a == 1 || b == 1)
            ans = 1;
        else if (a == 2 && b == 2)
            ans = 1;
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}

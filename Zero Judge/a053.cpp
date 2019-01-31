/*************************************************************************
  > File Name: a053.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep 23 09:28:39 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        if (0 <= n && n <= 10)
            cout << n * 6;
        else if (n <= 20)
            cout << 40 + n * 2;
        else if (n <= 40)
            cout << 60 + n;
        else cout << 100;
        cout << '\n';
    }
    return 0;
}

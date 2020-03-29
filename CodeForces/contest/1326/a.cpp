/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 19 22:34:31 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a == 1)
            cout << -1;
        else {
            cout << 2;
            while (--a)
                cout << 3;
        }
        cout << '\n';
    }
    return 0;
}

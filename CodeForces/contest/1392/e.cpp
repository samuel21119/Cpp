/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Aug 18 15:14:14 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, q;
ll input;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll out = 0;
        if (i & 1)
            out = 1 << (i - 1);
        for (int j = 0; j < n; j++) {
            cout << out << ' ';
            out <<= 1;
        }
        cout << endl;
    }
    cin >> q;
    while (q--) {
        cin >> input;
        int cnt = 2 * n - 1;
        int x, y; x = y = 1;
        bool cur = 0;
        cout << "1 1\n";
        while (--cnt) {
            if (cur) {
                if (input & 1)
                    y += 1;
                else
                    x += 1, cur = 0;
            }else {
                if (input & 1)
                    x += 1, cur = 1;
                else
                    y += 1;
            }
            input >>= 1;
            cout << x << ' ' << y << endl;
        }
    }
    return 0;
}

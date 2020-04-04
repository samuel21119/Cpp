/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Apr  4 10:07:57 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        cout << "Case #" << t << ": ";
        int now = 0;
        for (char i : s) {
            int x = i - '0';
            while (x > now) {
                now++;
                cout << '(';
            }
            while (x < now) {
                now--;
                cout << ')';
            }
            cout << x;
        }
        while (now--)
            cout << ')';
        cout << '\n';
    }
    return 0;
}

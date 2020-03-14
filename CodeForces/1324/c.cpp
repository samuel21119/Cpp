/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 12 21:23:54 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        int prev = -1;
        int mx = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                mx = max(mx, i - prev);
                prev = i;
            }
        }
        cout << max(mx, n - prev) << '\n';
    }
    return 0;
}

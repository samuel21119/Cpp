/*************************************************************************
  > File Name: d1.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 19 23:18:46 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        string s2;
        cin >> s;
        int n = s.length();
        int l, r;
        int lr, rl;
        l = 0; r = n - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }
            for (int a = l; a < r; a++) {
                int L = l;
                int R = a;
                bool is = 1;
                for (int t = 0; L + t < R - t; t++) {
                    is &= s[L + t] == s[R - t];
                }
                if (is) {
                    lr = a;
                }
            }
            for (int a = r; a > l; a--) {
                int L = a;
                int R = r;
                bool is = 1;
                for (int t = 0; L + t < R - t; t++) {
                    is &= s[L + t] == s[R - t];
                }
                if (is) {
                    rl = a;
                }
            }
            break;
        }
        if (r <= l) {
            cout << s << '\n';
        }else {
            for (int i = 0; i < l; i++)
                cout << s[i];
            if (lr - l > r - rl) {
                for (int i = l; i <= lr; i++)
                    cout << s[i];
            }else
                for (int i = rl; i <= r; i++)
                    cout << s[i];
            for (int i = r + 1; i < n; i++)
                cout << s[i];
            cout << '\n';
        }
    }
    return 0;
}

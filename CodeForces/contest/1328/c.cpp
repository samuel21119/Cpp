/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 26 22:51:58 2020
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
        string s;
        cin >> n >> s;
        string a1, a2;
        bool a2bigger = 0;
        for (int i = 0; i < n; i++) {
            int now = s[i] - '0';
            int half = now / 2;
            if (a2bigger) {
                a1 += now + '0';
                a2 += '0';
            }else {
                a1 += half + '0';
                a2 += now - half + '0';
                a2bigger |= now > half * 2;
            }
        }
        cout << a1 << '\n' << a2 << '\n';
    }
    return 0;
}

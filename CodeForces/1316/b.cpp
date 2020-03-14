/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar  4 22:39:41 2020
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
        if (n == 1) {
            cout << s << '\n' << "1\n";
            continue;
        }
        string t = s;
        int ans = 1;
        string a = s;
        for (int i = 2; i < n; i++) {
            t = s.substr(i - 1, n - i + 1);
            if ((i & 1) ^ (n & 1))
                t += s.substr(0, i - 1);
            else
                for (int j = i - 2; j >= 0; j--)
                    t += s[j];
            if (t < a) {
                ans = i;
                a = t;
            }
        }
        reverse(s.begin(), s.end());
        if (s < a) {
            ans = s.length();
            a = s;
        }
        cout << a << '\n' << ans << '\n';
    }
    return 0;
}

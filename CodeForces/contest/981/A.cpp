/*************************************************************************
  > File Name: Antipalindrome.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun May 27 22:53:10 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bool Npalindrome(string s, int start, int end) {
    if (end == -1)
        end = s.length() - 1;
    while (start <= end) {
        if (s[start++] != s[end--])
            return 1;
    }
    return 0;
}
void solve(string s) {
    if (Npalindrome(s, 0, -1)) {
        cout << s.length() << '\n';
        return;
    }
    int i, j;
    i = 1;
    j = s.length() - 1;
    while (i <= j) {
        if (Npalindrome(s, i, j)) {
            cout << j - i + 1 << '\n';
            return;
        }
        if (Npalindrome(s, i, --j)) {
            cout << j - i + 1 << '\n';
            return;
        }
        i++;
    }
    cout << "0\n";
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin >> s)
        solve(s);
    return 0;
}

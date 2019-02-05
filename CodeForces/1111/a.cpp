/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed 06 Feb 2019 12:13:38 AM CST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool check(char i) {
    return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < int(s1.length()); i++) {
        if (check(s1[i]) != check(s2[i])) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}

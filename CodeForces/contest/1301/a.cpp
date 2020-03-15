/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Feb 14 10:51:14 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> s1>>s2 >> s3;
        bool ans = 1;
        for (int i = 0; i < s1.length() && ans; i++) {
            ans &=s3[i] == s2[i] || s1[i] == s3[i];
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}

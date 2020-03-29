/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Mar 22 20:03:30 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool check(string &s, int start, int end) {
    bool ans = 1;
    for (int i = 0; start + i < end - i; i++) {
        ans &= s[i + start] == s[end - i];
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    cout << ((check(s, 0, n - 1) && check(s, 0, (n - 1) / 2 - 1) && check(s, (n + 3) / 2 - 1, n - 1)) ? "Yes" : "No")<< '\n';
    return 0;
}

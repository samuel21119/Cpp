/*************************************************************************
  > File Name: A.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jun 11 21:34:53 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int l = s.length();
    bool ans = false;
    for (int i = 1; i < l - 1 && !ans; i++) {
        if (s[i - 1] == '.' || s[i] == '.' || s[i + 1] == '.')
            continue;
        if (s[i - 1] != s[i] && s[i] != s[i + 1] && s[i - 1] != s[i + 1])
            ans = 1;
    } 
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}

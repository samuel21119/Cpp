/*************************************************************************
  > File Name: 10298 - Power String.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep  2 20:26:44 2018
*************************************************************************/

#include <bits/stdc++.h>
#define n s.length()
using namespace std;
string s;
int fail[1000010];
void build() {
    for (int i = 1, k = 0; i < s.length(); i++) {
        while (k && s[i] != s[k])
            k = fail[k - 1];
        if (s[i] == s[k])
            k++;
        fail[i] = k;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> s) {
        if (s[0] == '.')
            break;
        build();
        cout << n / (n - fail[n - 1]) << '\n';
    }
    return 0;
}

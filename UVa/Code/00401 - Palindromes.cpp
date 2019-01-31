/*************************************************************************
  > File Name: 00401 - Palindromes.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Sep 18 16:40:21 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
char re[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin >> s) {
        bool pa = 1;
        bool mirror = 1;
        for (int i = 0; i <= int(s.length()) / 2; i++) {
            int j = s.length() - i - 1;
            pa &= s[i] == s[j];
            if (isupper(s[j]) && s[i] != re[s[j] - 'A'])
                mirror = 0;
            if (isdigit(s[j]) && s[i] != re[s[j] - '1' + 26])
                mirror = 0;
        }
        cout << s << " -- ";
        if (pa && mirror)
            cout << "is a mirrored palindrome.\n";
        else if (pa)
            cout << "is a regular palindrome.\n";
        else if (mirror)
            cout << "is a mirrored string.\n";
        else
            cout << "is not a palindrome.\n";
        cout << '\n';
    }
    return 0;
}

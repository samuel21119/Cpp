/*************************************************************************
  > File Name: 12577 - Hajj-e-Akbar.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Dec 19 11:07:23 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int t = 1;
    while (cin >> s && s[0] != '*') {
        cout << "Case " << t++ << ": ";
        if (s[0] == 'H')
            cout << "Hajj-e-Akbar";
        else
            cout << "Hajj-e-Asghar";
        cout << '\n';
    }
    return 0;
}

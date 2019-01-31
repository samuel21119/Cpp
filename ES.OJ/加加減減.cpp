/*************************************************************************
  > File Name: 加加減減.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat May 19 07:45:41 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int ans, tmp;
    cin >> s;
    ans = tmp = 0;
    int length = s.length();
    bool as = 1;
    for (int i = 0; i < length; i++) {
        if (s[i] == '=') {
            if (as)
                ans += tmp;
            else
                ans -= tmp;
            break;
        }
        if (s[i] == '-') {
            if (as)
                ans += tmp;
            else
                ans -= tmp;
            tmp = 0;
            as = 0;
        }else if (s[i] == '+') {
            if (as)
                ans += tmp;
            else
                ans -= tmp;
            tmp = 0;
            as = 1;
        }
        else{
            tmp *= 10;
            tmp += s[i] - '0';
        }
    }
    cout << ans << '\n';
}

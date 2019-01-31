/*************************************************************************
  > File Name: 12542 - Prime Substring.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Oct 23 17:57:51 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int m = 100000;
bool p[m + 1];
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0] = p[1] = 1;
    for (int i = 2; i <= m; i++) {
        if (p[i])
            continue;
        for (int j = i << 1; j <= m; j += i)
            p[j] = 1;
    }
    while (cin >> s) {
        if (s == "0")
            break;
        int ans = 0;
        for (unsigned i = 0; i < s.length(); i++) {
            int sum = 0;
            for (unsigned j = i; j < s.length(); j++) {
                sum = sum * 10 + s[j] - '0';
                if (sum <= m) {
                    if (!p[sum])
                        ans = max(ans, sum);
                }else
                    break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

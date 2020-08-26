/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Aug 25 23:06:06 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

char ans[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int x;
        cin >> s >> x;
        string s2(s);
        int n = s.length();
        fill(ans, ans + n, '1');
        ans[n] = '\0';
        for (int i = 0; i < n; i++) {
            int a = i - x;
            int b = i + x;
            if (s[i] == '0') {
                if (a >= 0)
                    ans[a] = '0';
                if (b < n)
                    ans[b] = '0';
            }
        }
        for (int i = 0; i < n; i++) {
            int a = i - x;
            int b = i + x;
            s2[i] = '0';
            if (a >= 0 && ans[a] == '1')
                s2[i] = '1';
            if (b < n && ans[b] == '1')
                s2[i] = '1';
                
        }
        if (s2 == s)
            cout << ans;
        else
            cout << -1;
        cout << '\n';
    }
    return 0;
}

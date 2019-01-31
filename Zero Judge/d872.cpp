/*************************************************************************
  > File Name: d872.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 10 18:45:18 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int p, t[100001], len, ans, a1, a2;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> p) {
        string s;
        for (int i = 0; i < p; i++)
            cin >> t[i];
        sort(t, t + p);
        len = p;
        ans = 0;
        while (len >= 4) {
            a1 = t[0] * 2 + t[len - 1] + t[len - 2];
            a2 = t[0] + t[1] * 2 + t[len - 1];
            if (a1 < a2)
                ans += a1;
            else
                ans += a2;
            len -= 2;
        }
        switch (len) {
            case 3:
                ans += t[0] + t[1] + t[2];
                break;
            case 2:
                ans += t[1];
                break;
            case 1:
                ans += t[0];
        }
        cout << ans << '\n';
    }
    return 0;
}

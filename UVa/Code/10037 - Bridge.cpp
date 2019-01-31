/*************************************************************************
  > File Name: 10037 - Bridge.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:44:12 2017
*************************************************************************/

#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#define N '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _c, p, t[1002], len, ans, a1, a2;
    cin >> _c;
    while (_c--) {
        string s;
        cin >> p;
        for (int i = 0; i < p; i++)
            cin >> t[i];
        sort(t, t + p);
        len = p;
        ans = 0;
        while (len >= 4) {
            stringstream ss;
            string a, b, x, y;
            a1 = t[0] * 2 + t[len - 1] + t[len - 2];
            a2 = t[0] + t[1] * 2 + t[len - 1];
            ss << t[0]; ss >> a; ss.clear();
            ss << t[len - 2]; ss >> x; ss.clear();
            ss << t[len - 1]; ss >> y; ss.clear();
            if (a1 < a2) {
                s += a + ' ' + y + N + a + N + a + ' ' + x + N + a + N;
                ans += a1;
            }
            else {
                ss << t[1]; ss >> b;
                s += a + ' ' + b + N + a + N + x + ' ' + y + N + b + N;
                ans += a2;
            }
            len -= 2;
        }
        string a, b, c;
        stringstream ss;
        ss << t[0]; ss >> a; ss.clear();
        switch (len) {
            case 3:
                ss << t[1]; ss >> b; ss.clear();
                ss << t[2]; ss >> c;
                s += a + ' ' + b + N + a + N + a + ' ' + c + N;
                ans += t[0] + t[1] + t[2];
                break;
            case 2:
                ss << t[1]; ss >> b;
                s += a + ' ' + b + N;
                ans += t[1];
                break;
            case 1:
                s += a + N;
                ans += t[0];
        }
        cout << ans << '\n' << s << (_c ? "\n" : "");
    }
    return 0;
}


/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Sep 29 00:57:08 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, s, a, b;
struct input {
    int hour, minute;
}in[110];
int diff(int i, int j) {
    int re = in[j].hour * 60 + in[j].minute;
    re -= in[i].hour * 60 + in[i].minute;
    return re;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> in[i].hour >> in[i].minute;
    in[0].hour = in[0].minute = 0;
    if (diff(0, 1) >= s + 1) {
        cout << "0 0\n";
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        if (diff(i - 1, i) >= s * 2 + 2) {
            a = in[i - 1].hour;
            b = in[i - 1].minute;
            b += s + 1;
            while (b >= 60)
                a++, b -= 60;
            cout << a << ' ' << b << '\n';
            return 0;
        }
    }
    a = in[n].hour;
    b = in[n].minute;
    b += s + 1;
    while (b >= 60)
        a++, b -= 60;
    cout << a << ' ' << b << '\n';
    return 0;
}

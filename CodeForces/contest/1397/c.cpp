/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Aug 30 23:04:59 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
ll in[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    if (n == 1) {
        cout << "1 1\n" << -in[0] << '\n';
        for (int i = 0; i < 2; i++)
            cout << "1 1\n0\n";
        return 0;
    }
    cout << 1 << ' ' << n - 1 << '\n';
    for (int i = 0; i < n - 1; i++) {
        ll tmp = in[i] * (n - 1);
        cout << tmp << " \n"[i == n - 2];
        in[i] += tmp;
    }

    cout << n << ' ' << n << '\n';
    cout << -in[n - 1] << '\n';
    in[n - 1] = 0;

    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << -in[i] << ' ';
    }
    return 0;
}

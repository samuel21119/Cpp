/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar  5 00:43:45 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m, p;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t % p != 0)
            a = i;
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t % p != 0)
            b = i;
    }
    cout << a + b << '\n';
    return 0;
}

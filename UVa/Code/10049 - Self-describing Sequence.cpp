/*************************************************************************
  > File Name: 10049 - Self-describing Sequence.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar 28 15:18:22 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int table[700000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 2;;
    table[1] = 1; table[2] = 3;
    while (++n < 700000)
        table[n] = table[n - 1] + (lower_bound(table + 1, table + n, n) - table);
    while (cin >> n && n)
        cout << lower_bound(table, table + 700000, n) - table << '\n';
    return 0;
}

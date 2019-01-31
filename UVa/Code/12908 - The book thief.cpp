/*************************************************************************
  > File Name: 12908 - The book thief.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Dec 13 13:29:14 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> table;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int last = 0, n;
    for (int i = 1; last <= 100000000; i++) {
        table.emplace_back(last + i);
        last += i;
    }
    while (cin >> n && n) {
        int t = upper_bound(table.begin(), table.end(), n) - table.begin();
        cout << table[t] - n << ' ' << t + 1 << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 31 22:45:10 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int out[510][510];
int n, m;
int k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cout << "3 4\n";
    int mx = 1 << 17;
    int tmp = k;
    cout << (1 << 18) - 1 << ' ' << tmp  << ' '<< tmp << ' ' << 0 << '\n';
    cout << mx << ' ' << 0 << ' ' << tmp << ' ' << 0 << '\n';
    cout << mx << ' ' << mx << ' ' << (1 << 18) - 1 << ' ' << tmp << '\n';
    return 0;
}

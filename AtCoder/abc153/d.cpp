/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 17 19:12:42 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
long long x;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    int cnt = 0;
    while (x) {
        cnt++;
        x >>= 1;
    }
    cout << (1LL << cnt) - 1 << '\n';
    return 0;
}

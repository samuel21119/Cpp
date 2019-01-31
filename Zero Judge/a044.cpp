/*************************************************************************
  > File Name: a044.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep 23 09:25:51 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    while (cin >> n)
        cout << 1 + n + n * (n + 1) * (n - 1) / 6 << '\n';
    return 0;
}

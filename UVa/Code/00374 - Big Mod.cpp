/*************************************************************************
  > File Name: 374 - Big Mod.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar 14 16:36:17 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int m;
int mod (int b, int p) {
    if (p == 1)
        return b % m;
    if (p == 0)
        return 1;
    int temp;
    temp = mod(b, p >> 1);
    if (p & 1)
        return ((temp * temp) % m * b) % m;
    return (temp * temp) % m;
}
int main() {
    int b, p;
    while (cin >> b >> p >> m)
        cout << mod(b % m, p) << '\n';
    return 0;
}

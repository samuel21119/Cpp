/*************************************************************************
  > File Name: B.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed May 30 20:53:05 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x, y;
    cin >> x >> y;
    double xy = y * log(x);
    double yx = x * log(y);
    if (x == y)
        cout << "=";
    else if (xy < yx)
        cout << "<\n";
    else if (xy == yx)
        cout << "=\n";
    else
        cout << ">\n";
    return 0;
}

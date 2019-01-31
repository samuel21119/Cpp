/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Sep 21 22:36:56 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c;
    cin >> n;
    a = b = n / 3;
    c = n - a - b;
    while (!(a % 3) || !(b % 3) || !(c % 3)){
        if (!(c % 3)) {
            c--;
            b++;
            continue;
        }
        if (!(b % 3)) {
            b--;
            a++;
            continue;
        }
        if (!(a % 3)){
            a--;
            c++;
            continue;
        }
    }
    cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}

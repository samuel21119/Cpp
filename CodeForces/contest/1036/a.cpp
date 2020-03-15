/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Sep  7 22:22:27 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
unsigned long long a, b, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    c = b % a;
    cout << b / a + (c ? 1 : 0) << '\n';
    return 0;
}

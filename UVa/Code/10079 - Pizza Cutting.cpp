/*************************************************************************
  > File Name: 10079 - Pizza Cutting.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:54:05 2017
*************************************************************************/

#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a;
    while (cin >> a && a >= 0)
            cout << (a * a + a) / 2 + 1 << '\n';
    return 0;
}


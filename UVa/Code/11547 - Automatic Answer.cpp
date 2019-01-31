/*************************************************************************
  > File Name: 11547 - Automatic Answer.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:33:23 2017
*************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count;
    long long in;
    cin >> count;
    while (count--) {
        cin >> in;
        in *= 63; // 567/9
        in += 7492;
        in *= 5;
        in -= 498;
        in %= 100;
        cout << abs(in / 10) << '\n';
    }
    return 0;
}


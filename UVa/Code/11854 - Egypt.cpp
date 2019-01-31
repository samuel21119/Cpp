/*************************************************************************
  > File Name: 11854 - Egypt.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:34:13 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[3];
    while (1) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[2] == 0)
            break;
        if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    return 0;
}


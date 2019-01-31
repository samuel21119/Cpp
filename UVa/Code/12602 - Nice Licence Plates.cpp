/*************************************************************************
  > File Name: 12602 - Nice Licence Plates.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan  1 20:38:13 2018
*************************************************************************/

#include <iostream>
using namespace std;
int abs(int i) {return i > 0 ? i : -i;}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char a[9];
    int x, y, c;
    cin >> c;
    while (c--) {
        cin >> a;
        for (int i = 0; i < 3; i++)
            a[i] -= 'A';
        for (int i = 4; i < 8; i++)
            a[i] -= '0';
        x = a[0] * 26 * 26 + a[1] * 26 + a[2];
        y = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7];
        cout << (abs(x - y) <= 100 ? "nice\n" : "not nice\n");
    }
    return 0;
}

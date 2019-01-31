/*************************************************************************
  > File Name: 連環天則渾沌編.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Feb  1 13:02:34 2018
*************************************************************************/

#include <iostream>
#define mod 0x94878787LL
using namespace std;
typedef unsigned long long ull;
ull p(ull a, ull P) {
    if (P == 0) return 1;
    ull temp = p(a, P / 2);
    temp = (temp * temp) % mod;
    if (P & 1)
        temp = (temp * a) % mod;
    return temp;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ull c, x, y;
    int a, b, ab, t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ab = a - b;
        if (b < ab) {
            int t = ab; ab = b; b = t;
        }
        x = y = 1;
        for (int i = b + 1; i <= a; i++) x = (x * i) % mod;
        for (int i = 2; i <= ab; i++)    y = (y * i) % mod;
        c = x * p(y, mod - 2);
        cout << c % mod << '\n';
    }
}

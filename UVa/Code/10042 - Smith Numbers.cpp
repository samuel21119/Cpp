/*************************************************************************
  > File Name: 10042 - Smith Numbers.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:44:40 2017
*************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
bool f;
int d(int a) {
    int r = 0;
    while (a > 0) {
        r += a % 10;
        a /= 10;
    }
    return r;
}
int pd(int a) {
    int t, r;
    r = 0;
    f = 0;
    for (int i = 2; i <= sqrt(a); i++) {
        t = 0;
        while (!(a % i)){
            t++;
            a /= i;
            f = 1;
        }
        if (t)
            r += d(i) * t;
    }
    if (a != 1)
        r += d(a);
    return r;
}
int main() {
    int c, in;
    cin >> c;
    while (c--) {
        cin >> in;
        while(1) {
            in++;
            if (pd(in) == d(in) && f) {
                cout << in <<  '\n';
                break;
            }
        }
    }
    return 0;
}



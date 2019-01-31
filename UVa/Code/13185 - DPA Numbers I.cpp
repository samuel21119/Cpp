/*************************************************************************
  > File Name: 13185 - DPA Numbers I.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:38:14 2017
*************************************************************************/

#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, c, s;
    cin >> c;
    while (c--) {
        cin >> a;
        s = 0;
        for (int i = 1; i < a; i++)
            if (!(a % i))
                s += i;
        if (s == a)
            cout << "perfect\n";
        else if (s < a)
            cout << "deficient\n";
        else
            cout << "abundant\n";
    }
    return 0;
}


/*************************************************************************
  > File Name: 10025 - The +-1+-2...+-n=k Problem.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan  1 20:35:34 2018
*************************************************************************/

#include <iostream>
using namespace std;
int main() {
    int a, b, c, ans;
    cin >> c;
    while (c--) {
        cin >> a;
        b = a >= 0 ? 1 - a : 1 + a;
        ans = 1;
        while (b < 0 || (b != 0 && b % 2))
            b += ++ans;
        cout << ans << '\n';
        if (c) cout << '\n';
    }
    return 0;
}


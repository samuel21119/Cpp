/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Aug  8 22:49:05 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int square[318];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    for (int i = 1; i < 318; i++) square[i] = i*i;
    int a = upper_bound(square, square + 318, n) - square;
    if (a && square[a - 1] == n) a--;
    int res = n % a;
    tmp = n - res;
    while (res--) {
        cout << n - res << ' ';
    }

    while (tmp > 0) {
        for (int i = a - 1; i >= 0; i--)
            cout << tmp - i << ' ';
        tmp -= a;
    }
    cout << '\n';
}

/*************************************************************************
  > File Name: 10013 - Super long sums.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Sep  5 18:41:16 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int digits[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, a, b;
    cin >> c;
    while (c--) {
        cin >> n;
        for (int i = n; i; i--) {
            cin >> a >> b;
            digits[i] = a + b;
        }
        for (int i = 1; i <= n; i++)
            if (digits[i] > 9) {
                digits[i + 1] += digits[i] / 10;
                digits[i] %= 10;
            }
        for (int i = n; i; i--)
            cout << digits[i];
        cout << '\n';
        if (c)
            cout << '\n';
    }
    return 0;
}

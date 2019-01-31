/*************************************************************************
  > File Name: 00557 - Burger.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jul 13 15:23:32 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
double ans[50000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(4);
    ans[0] = 1;
    for (int i = 2; i <= 50000; i++)
        ans[i - 1] = ans[i - 2] * (2 * i - 3) / (2 * i - 2);
    int c, a;
    cin >> c;
    while (c--) {
        cin >> a;
        cout << 1 - ans[a / 2 - 1] << '\n';
    }
    return 0;
}

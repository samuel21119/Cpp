/*************************************************************************
  > File Name: 10323 - Factorial! You Must be Kidding.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Jul  5 10:14:03 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
long long dp[14];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 14; i++)
        dp[i] = dp[i - 1] * i;
    int a;
    while (cin >> a) {
        if (a < 0) {
            if (a % 2)
                cout << "Overflow!\n";
            else
                cout << "Underflow!\n";
        }
        else if (a > 13)
            cout << "Overflow!\n";
        else if (dp[a] < 10000)
            cout << "Underflow!\n";
        else
            cout << dp[a] << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: 11069 - A Graph Problem.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Feb 27 09:31:56 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[77];
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = dp[2] = dp[3] = 1;
    for (int i = 4; i < 77; i++)
        dp[i] = dp[i - 2] + dp[i - 3];
    while (cin >> n)
        cout << dp[n] + dp[n - 1] << '\n';
    return 0;
}

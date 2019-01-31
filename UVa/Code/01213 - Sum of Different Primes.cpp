/*************************************************************************
  > File Name: 01213 - Sum of Different Primes.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Jun 21 00:10:16 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int dp[1121][15];
vector<int> prime;
bool p[1121];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < 1121; i++) {
        if (p[i])
            continue;
        prime.push_back(i);
        for (int j = (i << 1); j < 1121; j += i)
            p[j] = 1;
    }
    dp[0][0] = 1;
    for (auto a : prime)
        for (int i = 1120; i >= a; i--)
            for (int j = 1; j <= 14; j++)
                dp[i][j] += dp[i - a][j - 1];
    int a, b;
    while (cin >> a >> b && a && b)
        cout << dp[a][b] << '\n';
}

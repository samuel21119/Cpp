/*************************************************************************
  > File Name: 884 - Factorial Factors.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan  1 20:30:34 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
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
    for (int i = 2; i <= 1000000; i++) {
        int temp = i;
        for (int j = 0; j < prime.size() && prime[j] <= sqrt(temp); j++)
            while (!(temp % prime[j])) {
                temp /= prime[j];
                dp[i]++;
            }
        if (temp > 1)
            dp[i]++;
        dp[i] += dp[i - 1];
    }
    int a;
    while (cin >> a)
        cout << dp[a] << '\n';
}

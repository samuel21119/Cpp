/*************************************************************************
  > File Name: 674 - Coin Change.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Feb  7 10:07:37 2018
*************************************************************************/

#include <iostream>
using namespace std;
int dp[7500];
int coins[] = {1, 5, 10, 25, 50};
int main() {
    for (int i = 0; i < 7500; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = coins[i]; j <= 7489; j++)
            dp[j] += dp[j - coins[i]];
    int input;
    while (cin >> input)
        cout << dp[input] << '\n';
}

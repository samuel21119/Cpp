/*************************************************************************
  > File Name: 10036 - Divisibility.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:41:45 2017
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
    int c, num, div, n[10002];
    cin >> c;
    while (c--) {
        cin >> num >> div;
        for (int i = 0; i < num; i++) {
            cin >> n[i];
            n[i] = abs(n[i]) % div;
            if (!n[i])
                i--, num--;
        }
        bool dp[10002][102];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 0; i < num; i++)
            for (int j = 0; j < div; j++)
                if (dp[i][j]) {
                    dp[i + 1][(j + n[i]) % div] = true;
                    dp[i + 1][(j - n[i] < 0 ? j - n[i] + div : j - n[i])] = true;
                }
        cout << (dp[num][0] ? "Divisible\n" : "Not divisible\n");
    }
    return 0;
}


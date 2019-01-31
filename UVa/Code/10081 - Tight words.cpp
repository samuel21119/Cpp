/*************************************************************************
  > File Name: 10081 - Tight words.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:54:38 2017
*************************************************************************/

#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int k, n;
    double dp[101][10], sum;
    while (scanf("%d%d", &k, &n) != EOF) {
        for (int i = 0; i <= k; i++)
            dp[1][i] = 1.0/(k + 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0)
                    dp[i][j] += dp[i - 1][j - 1];
                if (j + 1 <= k)
                    dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] /= k+1;
            }
        }
        sum = 0;
        for (int i = 0; i <= k; i++)
            sum += dp[n][i];
        printf("%.5f\n", sum * 100);
    }
    return 0;
}


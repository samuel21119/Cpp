/*************************************************************************
  > File Name: 11341 - Term Strategy.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jan 24 23:04:49 2018
***********************************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int input[12][102];
int dp[12][102];
int main() {
    int c;
    scanf("%d", &c);
    while (c--) {
        int N, M;
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &input[i][j]);
        for (int i = 0; i <= N; i++) for (int j = 0; j <= M; j++) dp[i][j] = -1;
        dp[0][0] = 0;
        int t = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (input[i][j] >= 5) {
                    t += j + 1;
                    break;
                }
        if (t > M) {
            printf("Peter, you shouldn't have played billiard that much.\n");
            continue;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; j + k + 1 <= M; k++)
                    if (input[i][k] >= 5 && dp[i][j] != -1) {
                        dp[i+1][j+k+1] = max(dp[i][j] + input[i][k], dp[i+1][k+j+1]);
                    }
            }
        }
        t = (float)dp[N][M]/N * 100 + 0.5;
        printf("Maximal possible average mark - %.2f.\n", ((float)t)/100);
    }
    return 0;
}

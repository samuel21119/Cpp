/*************************************************************************
  > File Name: 357 - Let Me Count The Ways.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:03:08 2017
*************************************************************************/

#include <cstdio>
int main() {
    char coin[] = {1, 5, 10, 25, 50};
    unsigned long long int dp[30003] = {1}; int in;
    for (int i = 0; i < 5; i++)
        for (int j = coin[i]; j < 30003; j++)
            dp[j] += dp[j - coin[i]];
    while (scanf("%d", &in) != EOF)
        if (dp[in] == 1)
            printf("There is only 1 way to produce %d cents change.\n", in);
        else
            printf("There are %lld ways to produce %d cents change.\n", dp[in], in);
    return 0;
}


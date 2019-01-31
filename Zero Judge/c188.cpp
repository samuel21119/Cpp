#include <cstdio>
int main() {
    unsigned long long dp[202] = {1};
    dp[0] = 1;
    int a;
    for (int i = 1; i < 202; i++)
        for (int j = i;j < 202; j++)
            dp[j] += dp[j - i];
    while (scanf("%d", &a) != EOF) printf("%llu\n",dp[a]);
}

/*************************************************************************
  > File Name: 10003 - Cutting Sticks.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:36:28 2017
*************************************************************************/

#include <cstdio>
const int MAX = 10000000;
int in[55];
int DP[1005][1005];
int a, b, ans;
int min(int x, int y) { return x < y ? x : y;}
int dp(int l, int r) {
    if (DP[l][r] != MAX) return DP[l][r];
    bool flag = false;
    for (int i = 0; i < b; i++) {
        if (l < in[i] && in[i] < r) {
            DP[l][r] = min (DP[l][r], dp(l, in[i]) + dp(in[i], r) + r - l);
            flag = true;
        }
    }
    if (!flag)
        DP[l][r] = 0;
    return DP[l][r];
}
int main() {
    while (scanf("%d", &a) == 1 && a) {
        scanf("%d", &b);
        ans = 0;
        for (int i = 0; i < b; i++)
            scanf("%d", in + i);
        for (int i = 0; i <= a; i++)
            for (int j = 0; j <= a; j++)
                DP[i][j] = MAX;
        ans = dp(0, a);
        printf("The minimum cutting is %d.\n", ans);
    }
    return 0;
}

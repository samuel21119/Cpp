/*************************************************************************
  > File Name: 00165 - Stamps.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Feb 16 16:53:08 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int h, k, mx;
int use[10], maxsum[10], ans[10];
char check[75];
int bit;
void search(int index) {
    if (index == k) {
        if (maxsum[k - 1] > mx) {
            mx = maxsum[k - 1];
            memcpy(ans, use, sizeof(ans));
        }
        return;
    }
    for (int i = use[index - 1] + 1; i <= maxsum[index - 1] + 1; i++) {
        memset(check, 0, sizeof(check));
        check[0] = 1;
        use[index] = i;
        for (int j = 0; j <= index; j++)
            for (int k = use[j]; k < 75; k++)
                check[k] |= check[k - use[j]] << 1;
        int j = 0;
        while (check[++j] & bit);
        maxsum[index] = j - 1;
        search(index + 1);
    }
}
int main() {
    while (scanf("%d%d", &h, &k) && h + k) {
        memset(use, 0, sizeof(use));
        ans[0] = use[0] = 1;
        maxsum[0] = h;
        mx = 0;
        bit = 1;
        for (int i = 0; i < h; i++)
            bit |= bit << 1;
        search(1);
        for (int i = 0; i < k; i++)
            printf("%3d", ans[i]);
        printf(" ->%3d\n", mx);
    }
    return 0;
}

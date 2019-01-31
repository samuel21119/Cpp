/*************************************************************************
  > File Name: 00836 - Largest Submatrix.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jul 16 10:44:05 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
string input[25];
int sum[26][26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, ans;
    cin >> c;
    while (c--) {
        cin >> input[0];
        ans = 0;
        int n = input[0].length();
        for (int i = 1; i < n; i++)
            cin >> input[i];
        memset(sum, 0 ,sizeof(sum));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                sum[i + 1][j + 1] = sum[i + 1][j] + input[i][j] - '0';
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) {
                int prev = 1;
                for (int cur = 1; cur <= n; cur++) {
                    if (sum[cur][j] - sum[cur][i - 1] < (j - i + 1)) {
                        prev = cur + 1;
                        continue;
                    }
                    ans = max(ans, (j - i + 1) * (cur - prev + 1));
                }
            }
        cout << ans << '\n';
        if (c)
            cout << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: 10564 - Paths through the Hourglass.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Jul 10 12:34:38 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[50][22][500];
int input[50][22];
int n, s;

void print(int deep, int j, int sum) {
    if (deep == n * 2 - 1)
        return;
    sum -= input[deep][j];
    if (deep < n) {
        if (j > 1 && dp[deep + 1][j - 1][sum]) {
            cout << "L";
            print(deep + 1, j - 1, sum);
            return;
        }
        cout << "R";
        print(deep + 1, j, sum);
        return;
    }
    if (dp[deep + 1][j][sum]) {
            cout << "L";
            print(deep + 1, j, sum);
            return;
    }
    cout << "R";
    print(deep + 1, j + 1, sum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> s && (n | s)) {
        for (int i = n; i; i--)
            for (int j = 1; j <= i; j++)
                cin >> input[n - i + 1][j];

        for (int i = 1; i < n; i++)
            for (int j = 1; j <= i + 1; j++)
                cin >> input[n + i][j];

        ll ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= n; j++)
            dp[2 * n - 1][j][input[2 * n - 1][j]] = 1;

        for (int i = 2 * n - 2; i >= n; i--)
            for (int j = 1; j <= i + 1 - n; j++)
                for (int k = input[i][j], l = input[i][j]; k <= s; k++)
                    dp[i][j][k] += dp[i + 1][j][k - l] + dp[i + 1][j + 1][k - l];
        for (int i = n - 1; i; i--)
            for (int j = 1; j <= n - i + 1; j++)
                for (int k = input[i][j], l = input[i][j]; k <= s; k++)
                    dp[i][j][k] += dp[i + 1][j - 1][k - l] + dp[i + 1][j][k - l];

        for (int j = 1; j <= n; j++)
            ans += dp[1][j][s];
        cout << ans << '\n';
        for (int j = 1; ans && j <= n; j++)
            if (dp[1][j][s]) {
                cout << j - 1 << ' ';
                print(1, j, s);
                break;
            }
        cout << '\n';
    }
    return 0;
}

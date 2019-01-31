/*************************************************************************
  > File Name: 10066 - The Twin Towers.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:48:47 2017
*************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dp[101][101];
    int na[101], ma[101];
    int n, m, c = 1;
    while (cin >> n >> m) {
        if (!(n + m))
            break;
        for (int i = 0; i < n; i++)
            cin >> na[i + 1];
        for (int i = 0; i < m; i++)
            cin >> ma[i + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (na[i] == ma[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        
        cout << "Twin Towers #" << c++ << "\nNumber of Tiles : " << dp[n][m] << "\n\n";
    }
    return 0;
}


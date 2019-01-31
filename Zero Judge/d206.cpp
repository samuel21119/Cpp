/*************************************************************************
  > File Name: d206.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 13 16:49:01 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int in[110][110];

int main() {
    int n;
    while (cin >> n) {
        memset(in, 0, sizeof(in));
        for (int i = 1; i <= n; i++) {
            cout << '\n';
            for (int j = 1; j <= n; j++) {
                cin >> in[i][j];
                in[i][j] += in[i - 1][j] + in[i][j - 1] - in[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++) {
                int tmp = 0;
                for (int k = 1; k <= n; k++) {
                    if (tmp > 0) {
                        tmp += in[i][k] - in[j - 1][k] - in[i][k - 1] + in[j - 1][k - 1];
                    }
                    else {
                        tmp = in[i][k] - in[j - 1][k] - in[i][k - 1] + in[j - 1][k - 1];
                    }
                    ans = max(ans, tmp);
                }
            }
        cout << ans << '\n';
    }
    return 0;
}

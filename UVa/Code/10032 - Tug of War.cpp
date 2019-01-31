/*************************************************************************
  > File Name: 10032 - Tug of War.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Feb 14 19:23:28 2018
*************************************************************************/

#include <iostream>
using namespace std;

long long dp[22600];
int input[110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, sum, Sh, Nh;
    cin >> c;
    while (c--) {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> input[i];
            sum += input[i];
        }
        Sh = sum >> 1;
        Nh = (n + 1) >> 1;
        for (int i = 1; i <= Sh; i++)
            dp[i] = 0;
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = Sh; j >= input[i]; j--)
                dp[j] |= dp[j - input[i]] << 1LL;
        for (int i = Sh; i >= 0; i--)
            if (dp[i] >> Nh & 1 || ((n & 1) && (dp[i] >> (Nh - 1) & 1))) {
                cout << i << ' ' << sum - i << '\n';
                break;
            }
        if (c)
            cout << '\n';
    }
}

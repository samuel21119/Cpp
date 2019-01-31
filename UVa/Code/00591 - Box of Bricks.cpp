/*************************************************************************
  > File Name: 00591 - Box of Bricks.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jun 13 17:00:51 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, input[55], sum, ans;
    c = 0;
    while (cin >> n && n) {
        sum = ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> input[i];
            sum += input[i];
        }
        sum /= n;
        for (int i = 0; i < n; i++)
            if (input[i] > sum)
                ans += input[i] - sum;
        cout << "Set #" << ++c << '\n' << "The minimum number of moves is " << ans << ".\n\n";
    }
    return 0;
}

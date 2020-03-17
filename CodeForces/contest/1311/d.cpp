/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 17 14:24:20 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int in[3], ans[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++)
            cin >> in[i];
        int sum = 1e9;
        for (int i = 1; i <= in[0] * 2 - 1; i++)
            for (int j = i; j <= in[1] * 2 - 1; j += i) {
                int tmp = in[2] / j * j;
                if (in[2] - tmp > tmp + j - in[2])
                    tmp += j;
                int a = abs(tmp - in[2]) + abs(j - in[1]) + abs(i - in[0]);
                if (a < sum) {
                    sum = a;
                    ans[0] = i; ans[1] = j; ans[2] = tmp;
                }
            }
        cout << sum << '\n';
        for (int i = 0; i < 3; i++)
            cout << ans[i] << ' ';
    }
    return 0;
}

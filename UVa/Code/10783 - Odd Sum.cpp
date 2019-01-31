/*************************************************************************
  > File Name: 10783 - Odd Sum.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jun 13 16:54:21 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, a, b, ans;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        ans = 0;
        cin >> a >> b;
        for (int i = a; i <= b; i++)
            if (i & 1)
                ans += i;
        cout << "Case " << i << ": " << ans << '\n';
    }
    return 0;
}

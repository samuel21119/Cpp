/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Dec 11 08:17:29 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, in[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    int ans = 1 << 30;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < n; j++)
            t += (i + j + abs(i - j)) * 2 * in[j];
        ans = min(ans, t);
    }
    cout << ans << '\n';
    return 0;
}

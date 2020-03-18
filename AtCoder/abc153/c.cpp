/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 17 19:08:52 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int in[200010];
long long ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in, in + n, [&](int a, int b) {
            return a > b;
            });
    for (int i = k; i < n; i++)
        ans += in[i];
    cout << ans << '\n';
    return 0;
}

/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Aug 18 10:17:35 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;
ll in[2100010];
ll mx;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        ll ans = 0;
        for (int i = 1; i < n; i++)
            if (in[i] < in[i - 1])
                ans += in[i - 1] - in[i];
        cout << ans << '\n';
    }
    return 0;
}

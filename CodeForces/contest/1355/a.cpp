/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon May 25 10:35:09 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, k, ans;
        cin >> n >> k;
        ans = n;
        while (--k) {
            int mx = 0, mn = 10;
            long long tmp = ans;
            while (tmp) {
                int now = tmp % 10;
                mx = max(mx, now);
                mn = min(mn, now);
                tmp /= 10;
            }
            if (mn == 0)
                break;
            ans += mx * mn;
        }
        cout << ans << '\n';
    }
    return 0;
}

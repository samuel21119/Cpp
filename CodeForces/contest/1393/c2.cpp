/*************************************************************************
  > File Name: c2.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Aug 27 16:42:57 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int mx = *max_element(cnt, cnt + n + 1);
        int mxcount = 0;
        for (int i = 0; i <= n; i++) 
            mxcount += cnt[i] == mx;
        cout << (mxcount - 1 + (n - mxcount * mx) / (mx - 1)) << '\n';
    }
    return 0;
}

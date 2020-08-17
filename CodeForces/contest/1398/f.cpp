/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Aug 15 21:06:31 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int cnt[2][1000010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    s = '0' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '?' || s[i] == '0') {
            cnt[0][i] = cnt[0][i - 1] + 1;
        }
        if (s[i] == '?' || s[i] == '1') {
            cnt[1][i] = cnt[1][i - 1] + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        int r = i;
        while (r <= n) {
            int mx = max(cnt[0][r], cnt[1][r]);
            if (mx >= i) {
                ans++;
                r += i;
            }else {
                r += i - mx;
            }
        }
        cout << ans << " \n"[i == n];
    }
    return 0;
}

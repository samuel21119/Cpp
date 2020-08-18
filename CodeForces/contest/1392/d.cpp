/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Aug 18 10:45:48 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int ans = 0;
        int cnt = 1, cnt2 = 1;
        while (cnt < n && s[cnt - 1] == s[cnt]) cnt++;
        if (cnt == n) {
            // RRR -> RRL
            cout << (cnt + 2) / 3 << '\n';
            continue;
        }
        for (int i = cnt + 1; i < n; i++) {
            if (s[i] == s[i - 1])
                cnt2++;
            else {
                ans += cnt2 / 3;
                cnt2 = 1;
            }
        }
        if (s[0] == s[n - 1])
            ans += (cnt + cnt2) / 3;
        else
            ans += cnt2 / 3 + cnt / 3;
        cout << ans << '\n';
    }
    return 0;
}

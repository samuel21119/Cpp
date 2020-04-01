/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 31 22:30:07 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int cnt[26];
bool parsed[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string str;
        cin >> n >> k;
        cin >> str;
        memset(parsed, 0, sizeof(bool) * n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (parsed[i])
                continue;
            memset(cnt, 0, sizeof(cnt));
            set<int> s;
            for (int j = i; j < n; j += k) {
                s.insert(j);
                s.insert(n - j - 1);
            }
            int mx = -1;
            for (int i : s) {
                parsed[i] = 1;
                cnt[str[i] - 'a']++;
                if (mx < cnt[str[i] - 'a']) {
                    mx = cnt[str[i] - 'a'];
                }
            }
            ans += (int)s.size() - mx;
        }
        cout << ans << '\n';
    }
    return 0;
}

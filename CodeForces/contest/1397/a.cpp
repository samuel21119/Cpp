/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Aug 30 22:34:22 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int cnt[30];
int len[1010];
string s[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            for (char j : s[i])
                cnt[j - 'a']++;
        }
        bool ans = 1;
        for (int i = 0; i < 26; i++)
            ans &= cnt[i] % n == 0;
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}

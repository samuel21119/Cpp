/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 14 22:41:27 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = 0;
        vector<int> v;
        int pre = 0;
        s += "0";
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            if (s[i] == s[pre])
                continue;
            if (s[pre] == '1')
                v.emplace_back(i - pre);
            pre = i;
        }
        sort(v.begin(), v.end());
        for (int i = (int)v.size() - 1; i >= 0; i -= 2)
            ans += v[i];
        cout << ans << '\n';
    }
    return 0;
}

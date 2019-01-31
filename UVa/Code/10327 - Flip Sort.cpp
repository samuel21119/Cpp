/*************************************************************************
  > File Name: 10327 - Flip Sort.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Dec  7 22:07:46 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int bit[1010];
int n;
int in[1010];
inline void add(int i) {
    while (i <= n + 1) {
        bit[i]++;
        i += i & -i;
    }
}
inline int sum(int i) {
    int re = 0;
    while (i) {
        re += bit[i];
        i -= i & -i;
    }
    return re;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
            v.emplace_back(in[i]);
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        int ans = 0;
        memset(bit, 0 , sizeof(bit));
        for (int i = 0; i < n; i++) {
            int now = lower_bound(v.begin(), v.end(), in[i]) - v.begin() + 1;
            ans += i - sum(now);
            add(now);
        }
        cout << "Minimum exchange operations : " << ans << '\n';
    }
    return 0;
}

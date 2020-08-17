/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon May 25 10:41:23 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int cnt[200010];
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cnt[i] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for (int i = 1; i <= n; i++) {
            int tmp = cnt[i] / i;
            ans += tmp;
            cnt[i + 1] += cnt[i] - tmp * i;
        }
        cout << ans << '\n';
    }
    return 0;
}

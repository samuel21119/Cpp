/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Mar  2 17:44:02 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int in[200010];
map<ll, ll> m;
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        m[in[i] - i] += in[i];
        ans = max(ans, m[in[i] - i]);
    }
    cout << ans << '\n';
    return 0;
}

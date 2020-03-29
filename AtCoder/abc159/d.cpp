/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Mar 22 20:12:48 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int in[200010];
ll ans[200010];
ll sum;
map<int, ll> m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        m[in[i]]++;
    }
    for (auto i : m) {
        sum += (i.second - 1) * i.second / 2;
    }
    for (int i = 0; i < n; i++) {
        ll num = m[in[i]];
        cout << sum - num * (num - 1) / 2 + (num - 1) * (num - 2) / 2 << '\n';
    }
    return 0;
}

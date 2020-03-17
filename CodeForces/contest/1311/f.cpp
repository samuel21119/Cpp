/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 17 11:42:12 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
pair<int, int> in[200010];
ll bit1[200010], bit2[200010], ans;
void add(int i, int dx, ll *bit) {
    while (i <= n) {
        bit[i] += dx;
        i += i & -i;
    }
}
ll query(int i, ll *bit) {
    ll re = 0;
    while (i) {
        re += bit[i];
        i -= i & -i;
    }
    return re;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i].first;
    for (int i = 0; i < n; i++) {
        cin >> in[i].second;
        v.emplace_back(in[i].second);
    }
    sort(in, in + n);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int ind = lower_bound(v.begin(), v.end(), in[0].second) - v.begin() + 1;
    add(ind, in[0].first, bit1);
    add(ind, 1, bit2);
    for (int i = 1; i < n; i++) {
        int xi = in[i].first;
        int vi = in[i].second;
        int ind = lower_bound(v.begin(), v.end(), vi) - v.begin() + 1;
        ans += query(ind, bit2) * xi - query(ind, bit1);
        add(ind, xi, bit1);
        add(ind, 1, bit2);
    }
    cout << ans << '\n';
    return 0;
}

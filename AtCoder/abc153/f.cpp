/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 17 19:27:57 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, d, a;
pair<ll, ll> monsters[200010];
ll tree[800010];
ll lazy[800010];
int make_tree(int ind, int l, int r) {
    if (l == r)
        return tree[ind] = monsters[l].second;
    int m = (l + r) / 2;
    int ind2 = ind * 2;
    return tree[ind] = max(make_tree(ind2 + 1, l, m), make_tree(ind2 + 2, m + 1, r));
}
void change(int ind, int l, int r, int s, int e, int dx) {
    if (s > r || e < l)
        return;
    if (s <= l && r <= e) {
        lazy[ind] += dx;
        return;
    }
    int m = (l + r) / 2;
    int ind2 = ind * 2;
    change(ind2 + 1, l, m, s, e, dx);
    change(ind2 + 2, m + 1, r, s, e, dx);
    tree[ind] = max(tree[ind2 + 1] + lazy[ind2 + 1], tree[ind2 + 2] + lazy[ind2 + 2]);
}
int query(int ind, int l, int r, int s, int e) {
    if (s > r || e < l)
        return 0;
    if (s <= l && r <= e)
        return tree[ind] + lazy[ind];
    int m = (l + r) / 2;
    int ind2 = ind * 2;
    return max(query(ind2 + 1, l, m, s, e), query(ind2 + 2, m + 1, r, s, e)) + lazy[ind];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> a;
    for (int i = 0; i < n; i++)
        cin >> monsters[i].first >> monsters[i].second;
    sort(monsters, monsters + n);
    make_tree(0, 0, n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ll t = monsters[i].first;
        ll tt = t + 2 * d;
        int ind = lower_bound(monsters, monsters + n, pair<ll, ll>(tt, 0)) - monsters;
        if (ind == n || monsters[ind].first > tt)
            ind--;
        ll now = query(0, 0, n, i, i);
        if (now <= 0)
            continue;
        ll dx = now / a;
        dx += now % a != 0;
        ans += dx;
        change(0, 0, n, i, ind, -dx * a);
    }
    cout << ans << '\n';
    return 0;
}

/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar  7 09:56:48 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll two = 500000004;
vector<int> all;
int n, q;
int sz;
int in[300010];
pair<int, int> changes[300010];
ll dp[1500010];
ll pow(int i) {
    if (i <= 0)
        return 1;
    if (i == 1)
        return two;
    if (dp[i]) return dp[i];
    ll t = pow(i / 2);
    return  dp[i] = t * t % mod * (i & 1 ? two : 1) % mod;
}
struct node {
    ll val;
    ll sumR; // Right is bigger
    ll sumL;
    int cnt;
    node() {val = sumL = sumR = cnt = 0;}
    node(int a, int b, int c, int d) {
        val = a; sumL = b, sumR = c, cnt = d;
    }
}tree[2400000];
void modify(int index, int l, int r, int target, int dx) {
    node &cur = tree[index];
    if (l == r && l == target) {
        target = all[target];
        if (dx == 1) {
            cur.cnt++;
            cur.sumR = cur.sumL = (cur.sumL + target * pow(cur.cnt)) % mod;
            cur.val = (cur.val * two % mod + (cur.cnt - 1) * two % mod * two % mod * target % mod * target % mod) % mod;
        }else {
            cur.sumR = cur.sumL = (cur.sumL - target * pow(cur.cnt) % mod + mod) % mod;
            cur.val = (cur.val - (cur.cnt - 1) * two % mod * two % mod * target % mod * target % mod + mod) % mod;
            cur.val = cur.val * 2 % mod;
            cur.cnt--;
        }
        return;
    }
    if (l > target || r < target)
        return;
    int m = (l + r) / 2, ind2 = index * 2;
    modify(ind2 + 1, l, m, target, dx);
    modify(ind2 + 2, m + 1, r, target, dx);
    node &L = tree[ind2 + 1];
    node &R = tree[ind2 + 2];
    cur.val = (L.val + R.val + (L.sumR * R.sumL % mod)) % mod;
    cur.sumL = (L.sumL + R.sumL * pow(L.cnt)) % mod;
    cur.sumR = (R.sumR + L.sumR * pow(R.cnt)) % mod;
    cur.cnt = L.cnt + R.cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        all.emplace_back(in[i]);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        changes[i] = {a, b};
        all.emplace_back(b);
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    sz = all.size() - 1;
    for (int i = 1; i <= n; i++) {
        int index = lower_bound(all.begin(), all.end(), in[i]) - all.begin();
        modify(0, 0, sz, index, 1);
        in[i] = index;
    }
    cout << tree[0].val << '\n';
    for (int i = 0; i < q; i++) {
        int index = changes[i].first;
        int val = lower_bound(all.begin(), all.end(), changes[i].second) - all.begin();
        modify(0, 0, sz, in[index], -1);
        in[index] = val;
        modify(0, 0, sz, in[index], 1);
        cout << tree[0].val << '\n';
    }
    return 0;
}

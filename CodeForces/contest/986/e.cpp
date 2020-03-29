/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar 25 11:14:23 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int n, q, mx;
vector<int> link[100010];;
int val[100010], query[100010];
ll ans[100010];

int dfs_time;
int tree_in[100010], tree_out[100010];
void dfs(int now, int parent) {
    tree_in[now] = ++dfs_time;
    for (int i : link[now])
        if (i != parent)
            dfs(i, now);
    tree_out[now] = ++dfs_time;
}

bool p[10000010];
vector<int> prime;
vector<pair<int, int>> sorted_query[700000];

struct node {
    ll mul;
    int cnt;
    ll lazy;
    node() {
        cnt = 0;
        mul = 1;
        lazy = 1;
    }
}seg[1000000];
void push(int n, int l, int r) {
    if (seg[n].lazy == -1) {
        seg[n].lazy = 1;
        seg[n].mul = 1;
        seg[l].lazy = seg[r].lazy = -1;
    }else if (seg[n].lazy > 1) {
        seg[n].mul = (seg[n].mul * seg[n].lazy) % mod;
        seg[l].lazy = (seg[l].lazy * seg[n].lazy) % mod;
        seg[r].lazy = (seg[r].lazy * seg[n].lazy) % mod;
        seg[n].lazy = 1;
    }
}
ll modify(int ind, int l, int r, int s, int e, int x) {
    if (l > e || r < s) {
        return 1;
    }
    if (s <= l && r <= e) {
        seg[ind].lazy = seg[ind].lazy * x % mod;
        return 
    }
    int m = (l + r) / 2;
    int ind2 = ind * 2;
    push(ind, ind2 + 1, ind2 + 2);
    ll L = modify(ind2 + 1, l, m, s, e, x);
    ll R = modify(ind2 + 2, m + 1, r, s, e, x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        link[a].emplace_back(b);
        link[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        query[i] = a;
    }
    prime.emplace_back(2);
    for (int i = 3; i <= mx; i++) {
        if (p[i])
            continue;
        prime.emplace_back(i);
        for (int j = i * 2; j <= mx; j += i)
            p[j] = 1;
    }
    for (int i = 0; i < (int)prime.size(); i++) {
        int p = prime[i];
        for (int j = 0; j < q; j++) {
            int cur = query[j];
            int cnt = 0;
            while (cur % p == 0) {
                cur /= p;
                cnt++;
            }
            if (cnt)
                sorted_query[i].push_back({cnt, j});
        }
        sort(sorted_query[i].begin(), sorted_query[i].end());
    }
    return 0;
}

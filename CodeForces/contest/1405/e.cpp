/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep 10 15:07:34 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int n, q;
int in[300010];
vector<pii> query[300010]; // index: end
int ans[300010], out[300010];
struct BITree {
    int num[300010];
    BITree() {
        memset(num, 0, sizeof(num));
    }
    void add(int x, int y) {
        while (x <= n) {
            num[x] += y;
            x += x & -x;
        }
    }
    int query(int x) {
        int re = 0;
        while (x) {
            re += num[x];
            x -= x & -x;
        }
        return re;
    }
}bit;
int find(int now) {
    int all = ans[now];
    int fn = in[now];
    int l = 0, r = now;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (all - bit.query(m) >= fn)
            l = m;
        else
            r = m;
    }
    return l;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        in[i] = i - in[i];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        query[n - b].emplace_back(pii(a, i));
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1];
        if (in[i] >= 0 && ans[i - 1] >= in[i]) {
            int last = find(i);
            bit.add(last + 1, 1);
            ans[i]++;
        }
        for (pii &x : query[i])
            out[x.second] = ans[i] - bit.query(x.first);
    }
    for (int i = 0; i < q; i++)
        cout << out[i] << '\n';
    return 0;
}

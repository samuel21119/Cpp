/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar  3 11:52:36 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m, p;
int ans = INT_MIN;
struct T {
    int func, coin;
    T() {}
    T(int a, int b) {
        func = a, coin = b;
    }
}weapons[200010], armors[200010];
struct M {
    int atk, def, coin;
    M() {}
    M(int a, int b, int c) {
        def = a, atk = b, coin = c;
    }
}monsters[200010];
int t[200010];
struct node {
    int data, lazy;
}tree[200010 * 4];
int make_tree(int l, int r, int index) {
    tree[index].lazy = 0;
    if (l == r)
        return tree[index].data = -armors[l].coin;
    int m = (l + r) >> 1;
    int index2 = index << 1;
    return tree[index].data = max(make_tree(l, m, index2 + 1), make_tree(m + 1, r, index2 + 2));
}
int query(int l, int r, int s, int e, int index) {
    if (l > e || r < s)
        return INT_MIN;
    if (s <= l && r <= e)
        return tree[index].data + tree[index].lazy;
    int m = (l + r) >> 1;
    int index2 = index << 1;
    return max(query(l, m, s, e, index2 + 1), query(m + 1, r, s, e, index2 + 2)) + tree[index].lazy;
}
void modify(int l, int r, int s, int e, int index, int dx) {
    if (l > e || r < s)
        return;
    if (s <= l && r <= e)
        tree[index].lazy += dx;
    else {
        int m = (l + r) >> 1;
        int index2 = index << 1;
        modify(l, m, s, e, index2 + 1, dx);
        modify(m + 1, r, s, e, index2 + 2, dx);
        tree[index].data = max(tree[index2 + 1].data + tree[index2 + 1].lazy,
                               tree[index2 + 2].data + tree[index2 + 2].lazy);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        weapons[i] = {a, b};
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        armors[i] = {a, b};
    }
    for (int i = 0; i < p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        monsters[i] = {a, b, c};
    }
    sort(armors, armors + m, [](T &a, T &b){return a.func < b.func;});
    sort(weapons, weapons + n, [](T &a, T &b){return a.func < b.func;});
    sort(monsters, monsters + p, [](M &a, M &b){return a.def < b.def;});
    make_tree(0, m - 1, 0);
    for (int i = 0; i < m; i++)
        t[i] = armors[i].func;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        while (ptr < p && weapons[i].func > monsters[ptr].def) {
            int ind = upper_bound(t, t + m, monsters[ptr].atk) - t;
            if (ind < m)
                modify(0, m - 1, ind, m - 1, 0, monsters[ptr].coin);
            ptr++;
        }
        ans = max(ans, query(0, m - 1, 0, m - 1, 0) - weapons[i].coin);
    }
    cout << ans << '\n';
    return 0;
}

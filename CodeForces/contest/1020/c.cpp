/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Aug 11 22:58:44 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define maxn 3001
struct node {
    int data, lazy;
}tree[maxn * 4];
// root = 0
int vote[3001];
int num[3001];
int n, m;
long long dp[3001][1501];
int make_tree(int l, int r, int index) {
    tree[index].lazy = 0;
    if (l == r)
        return tree[index].data = num[l];
    int m = (l + r) >> 1;
    int index2 = index << 1;
    return tree[index].data = max(make_tree(l, m, index2 + 1), make_tree(m + 1, r, index2 + 2));
}
int query(int l, int r, int s, int e, int index) {
    if (l > e || r < s)
        return -10000000;
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
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        num[a]++;
        vote[i] = b;
    }
    make_tree(0, n - 1, 0);
    int hn = n / 2 + 1;
    for (int i = 0; i < m; i++) {
        for (int j = hn; j > 0; j--)
    }
    return 0;
}

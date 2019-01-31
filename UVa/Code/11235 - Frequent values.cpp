/*************************************************************************
  > File Name: 11235 - Frequent values.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Jul  3 11:59:28 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, q;
int Start, End;
int input[100005];
struct T {
    int suml, summ, sumr;
    int l, r;
    T () {suml = summ = sumr = 0; l = r = -1;}
    T (int l, int m, int r) : suml(l), summ(m), sumr(r) {}
    bool operator == (T const &b) const {
        bool a = 1;
        a &= suml == b.suml;
        a &= summ == b.summ;
        a &= sumr == b.sumr;
        return a;
    }
}tree[400000];
T combine (T t1, T t2) {
    T re;
    int l1 = t1.l;
    int r1 = t1.r;
    int l2 = t2.l;
    int r2 = t2.r;
    if (t1 == (T){0, 0, 0})
        return t2;
    if (t2 == (T){0, 0, 0})
        return t1;
    int len = r2 - l1 + 1;
    re.l = l1;
    re.r = r2;
    if (input[l1] == input[r2]) {
        re.suml = re.summ = re.sumr = len;
        return re;
    }
    re.suml = t1.suml;
    re.sumr = t2.sumr;
    re.summ = max(t1.summ, t2.summ);
    if (input[r1] == input[l2])
        re.summ = max(re.summ, t1.sumr + t2.suml);
    if (input[l1] == input[l2])
        re.suml += t2.suml;
    if (input[r1] == input[r2])
        re.sumr += t1.sumr;
    re.summ = max(re.summ, re.suml);
    re.summ = max(re.summ, re.sumr);
    return re;
}
void maketree(int l, int r, int index) {
    if (l == r) {
        tree[index] = {1, 1, 1};
        tree[index].r = tree[index].l = l;
        return;
    }
    int m = (l + r) >> 1;
    int index2 = index << 1;
    maketree(l, m, index2 + 1);
    maketree(m + 1, r, index2 + 2);
    tree[index] = combine(tree[index2 + 1], tree[index2 + 2]);
}

T query(int l, int r, int index) {
    if (l > End || r < Start)
        return (T) {0, 0, 0};
    if (Start <= l && r <= End)
        return tree[index];
    int m = (l + r) >> 1;
    int index2 = index << 1;
    T t1 = query(l, m, index2 + 1);
    T t2 = query(m + 1, r, index2 + 2);
    return combine(t1, t2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> q) {
        for (int i = 0; i < n; i++)
            cin >> input[i];
        maketree(0, n - 1, 0);
        while (q--) {
            cin >> Start >> End;
            Start--; End--;
            T ans = query(0, n - 1, 0);
            cout << ans.summ << '\n';
        }
    }
    return 0;
}

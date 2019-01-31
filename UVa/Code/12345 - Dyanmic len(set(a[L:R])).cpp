/*************************************************************************
  > File Name: 12345 - Dyanmic len(set(a[L:R])).cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Oct 26 17:29:15 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, m, ans, l, r, t, block;
int in[50010];
int cnt[1000010];
struct Q {
    int l, r, id;
    int l_block, r_block, t;
    Q(int _l, int _r, int _id, int _l_block, int _r_block, int _t) {
        l = _l; r = _r; id = _id;
        l_block = _l_block; r_block = _r_block; t = _t;
    }
    bool operator< (const Q &b) const {
        if (l_block != b.l_block)
            return l_block < b.l_block;
        if (r_block != b.r_block)
            return r_block < b.r_block;
        return t < b.t;
    }
};
struct M {
    int index, number, last;
    M(int i, int n, int l) {
        index = i;
        number = n;
        last = l;
    }
};
vector<Q> query;
vector<M> modify;
vector<int> out;
int id;

inline void add_num(int i) {
    if (!cnt[i]++)
        ans++;
}
inline void del_num(int i) {
    if (!--cnt[i])
        ans--;
}
inline void time_forward(int l, int r, int t) {
    M &m = modify[t];
    if (l <= m.index && m.index <= r) {
        del_num(in[m.index]);
        add_num(m.number);
    }
    in[m.index] = m.number;
}
inline void time_backward(int l, int r, int t) {
    M &m = modify[t];
    if (l <= m.index && m.index <= r) {
        del_num(in[m.index]);
        add_num(m.last);
    }
    in[m.index] = m.last;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    block = pow(n, 2.0 / 3.0);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    t = -1;
    while (m--) {
        char cmd;
        int a, b;
        cin >> cmd >> a >> b;
        if (cmd == 'Q')
            query.emplace_back(Q(a, b - 1, id++, l / block, r / block, t));
        else {
            modify.emplace_back(M(a, b, in[a]));
            in[a] = b;
            t++;
        }
    }
    out.resize(query.size());
    sort(query.begin(), query.end());
    l = 0; r = -1;

    for (Q &i : query) {
        while (t < i.t)
            time_forward(l, r, ++t);
        while (t > i.t)
            time_backward(l, r, t--);
        while (r < i.r)
            add_num(in[++r]);
        while (l > i.l)
            add_num(in[--l]);
        while (r > i.r)
            del_num(in[r--]);
        while (l < i.l)
            del_num(in[l++]);
        out[i.id] = ans;
    }
    for (int &i : out)
        cout << i << '\n';
    return 0;
}

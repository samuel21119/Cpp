/*************************************************************************
 > File Name: 12538 - Version Controlled IDE.cpp
 > Author: Samuel
 > Mail: enminghuang21119@gmail.com
 > Created Time: Sun Aug 26 00:22:34 2018
 *************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, cnt, cmd, version;
int a, b, c;
string s;

struct node {
    int s;
    char c;
    node *l, *r;
    node(char _c):c(_c) {
        s = 1;
        l = r = nullptr;
    }
    inline void up() {
        s = 1 + (l ? l->s : 0) + (r ? r->s : 0);
    }
    void print() {
        if (l)
            l->print();
        cout << c;
        if (c == 'c')
            cnt++;
        if (r)
            r->print();
    }
}*root[50010];
inline int size(node *o) {
    return o ? o->s : 0;
}
void build(node *&o, int l, int r, string &s) {
    if (l > r)
        return;
    int m = (l + r) >> 1;
    o = new node(s[m]);
    build(o->l, l, m - 1, s);
    build(o->r, m + 1, r, s);
    o->up();
}
node* merge(node *a, node *b) {
    if (!a || !b)
        return a ? (new node(*a)) : (new node(*b));
    if (rand() % (a->s + b->s) < a->s) {
        a = new node(*a);
        a->r = merge(a->r, b);
        a->up();
        return a;
    }
    b = new node(*b);
    b->l = merge(a, b->l);
    b->up();
    return b;
}
void split(node *o, node *&a, node *&b, int k) {
    if (!o)
        a = b = nullptr;
    else if (k == 0) {
        a = nullptr;
        b = new node(*o);
    }else {
        if (k >= size(o->l) + 1) {
            a = new node(*o);
            split(o->r, a->r, b, k - size(o->l) - 1);
            a->up();
        }else {
            b = new node(*o);
            split(o->l, a, b->l, k);
            b->up();
        }
    }
}
void insert(int x, string &s) {
    node *a, *b, *c;
    split(root[version], a, c, x);
    build(b, 0, s.length() - 1, s);
    root[++version] = merge(a, merge(b, c));
    return;
}
void erase(int x, int k) {
    node *a, *b, *b2, *c;
    split(root[version], a, b, x - 1);
    split(b, b2, c, k);
    root[++version] = merge(a, c);
}
void print(int v, int s, int e) {
    node *a, *b, *b2, *c;
    split(root[v], a, b, s - 1);
    split(b, b2, c, e);
    b2->print();
    //root[v] = merge(a, merge(b2, c));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> a >> s;
            insert(a - cnt, s);
        }else if (cmd == 2) {
            cin >> a >> b;
            erase(a - cnt, b - cnt);
        }else {
            cin >> a >> b >> c;
            print(a - cnt, b - cnt, c - cnt);
            cout << '\n';
        }
    }
    return 0;
}

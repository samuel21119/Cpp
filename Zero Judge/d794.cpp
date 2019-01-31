/*************************************************************************
  > File Name: d794.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Aug 14 11:19:17 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int rand() {
    static int x = 123456789;
    return x += (x << 2) + 1;
}
template <typename T>
struct treap {
    struct node {
        node *l, *r;
        T key;
        int pri, size;
        node(T k):key(k) {
            l = r = nullptr;
            pri = rand();
            size = 1;
        }
        void up() {
            size = 1;
            if (l)
                size += l->size;
            if (r)
                size += r->size;
        }
    };

    node *root = nullptr;
    int size(node *a) {
        if (!a)
            return 0;
        return a->size;
    }
    node* merge(node *a, node *b) {
        if (!a || !b)
            return a ? a : b;
        if (a->pri < b->pri) {
            a->r = merge(a->r, b);
            a->up();
            return a;
        }
        b->l = merge(a, b->l);
        b->up();
        return b;
    }
    void split(node *R, node *&a, node *&b, T k) {
        if (!R)
            a = b = nullptr;
        else if (R->key < k) {
            a = R;
            split(R->r, a->r, b, k);
            R->up();
        }else {
            b = R;
            split(R->l, a, b->l, k);
            R->up();
        }
    }
    void insert(node *&Root, T k) {
        node *a, *b;
        split(Root, a, b, k);
        Root = merge(a, merge(new node(k), b));
    }
    bool erase(node *&R, T k) {
        if (!R)
            return 0;
        if (R->key == k) {
            node *tmp = R;
            R = merge(R->l, R->r);
            delete tmp;
            return 1;
        }
        node *&nxt = R->key > k ? R->l : R->r;
        if (erase(nxt, k)) {
            R->up();
            return 1;
        }
        return 0;
    }
    void split2(node *R, node *&a, node *&b, int k) {
        if (!R)
            a = b = nullptr;
        else {
            if (k >= size(R->l) + 1) {
                a = R;
                split2(R->r, a->r, b, k - size(R->l) - 1);
            }else {
                b = R;
                split2(R->l, a, b->l, k);
            }
            R->up();
        }
    }

    //Simple way to use:
    void insert(T k) {
        insert(root, k);
    }
    bool erase(T k) {
        return erase(root, k);
    }
    int rank(T k) {
        node *a, *b;
        split(root, a, b, k);
        int re = size(a);
        root = merge(a, b);
        return re;
    }
    node* kth(int k) {
        node *a, *b, *c;
        a = b = c = nullptr;
        split2(root, a, c, k);
        split2(a, a, b, k - 1);
        root = merge(merge(a, b), c);
        return b;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ull in;
    int n;
    while (cin >> n) {
        treap<ull> t;
        for (int i = 1; i <= n; i++) {
            cin >> in;
            t.insert(in);
            cout << i - t.rank(in) << '\n';
        }
    }
    return 0;
}

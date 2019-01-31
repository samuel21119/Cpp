/*************************************************************************
  > File Name: 01479 - Graph and Queries.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 17 09:26:25 2018
*************************************************************************/

#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int n, m;
int rand() {
    static int x = 123456789;
    return x += (x << 2) + 1;
}
struct node {
    node *l, *r;
    int key, s, pri;
    node(){l = r = nullptr;}
    node(int k): key(k){l = r = nullptr; s = 1; pri = rand();};
    void up() {
        s = 1;
        if (l)
            s += l->s;
        if (r)
            s += r->s;
    }
};
int size(node *a) {
    return a ? a->s : 0;
}
node* root[20010];
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
void split(node *o, node *&a, node *&b, int k) {
    if (!o)
        a = b = nullptr;
    else {
        if (o->key < k) {
            a = o;
            split(o->r, a->r, b, k);
        }else {
            b = o;
            split(o->l, a, b->l, k);
        }
        o->up();
    }
}
void insert(node *&root, int k) {
    node *a, *b;
    split(root, a, b, k);
    root = merge(a, merge(new node(k), b));
}
bool erase(node *&o, int k) {
    if (!o)
        return 0;
    if (o->key == k) {
        node *tmp = o;
        o = merge(o->l, o->r);
        delete tmp;
        return 1;
    }
    node *&next = (o->key > k ? o->l : o->r);
    if (erase(next, k))
        return o->up(), 1;
    return 0;
}
node* kth(node *o, int k) {
    if (!o || k <= 0 || k > o->s)
        return nullptr;
    if (size(o->r) + 1 == k)
        return o;
    if (size(o->r) >= k)
        return kth(o->r, k);
    return kth(o->l, k - size(o->r) - 1);
}
void merge_tree(node *&o, node *&target) {
    if (!o)
        return;
    if (o->l)
        merge_tree(o->l, target);
    if (o->r)
        merge_tree(o->r, target);
    insert(target, o->key);
    delete o;
    o = nullptr;
}
int parent[20010];
int p(int x) {
    return x == parent[x] ? x : parent[x] = p(parent[x]);
}
void merge_point(int a, int b) {
    a = p(a);
    b = p(b);
    if (a == b)
        return;
    if (root[a]->s < root[b]->s)
        swap(a, b);
    parent[b] = a;
    merge_tree(root[b], root[a]);
}
struct CMD {
    char c;
    int a, b;
}cmd[1 << 20];
int w[20010];
bool connect[60010];
pair<int, int> joint[60010];

int main() {
    int a, b, q, cas = 1;
    char c;
    double sum;
    int divid;
    while (cin >> n >> m && n) {
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        memset(connect, 0, sizeof(connect));
        for (int i = 1; i <= m; i++)
            cin >> joint[i].F >> joint[i].S;
        for (q = 0; ; ) {
            cin >> c;
            if (c == 'E')
                break;
            cin >> a;
            if (c == 'D')
                connect[a] = 1;
            else {
                cin >> b;
                if (c == 'C')
                    swap(b, w[a]);
            }
            cmd[q++] = {c, a, b};
        }
        for (int i = 1; i <= n; i++) {
            root[i] = nullptr;
            insert(root[i], w[i]);
            parent[i] = i;
        }
        for (int i = 1; i <= m; i++)
            if (!connect[i])
                merge_point(joint[i].F, joint[i].S);
        divid = sum = 0;
        while (q--) {
            a = cmd[q].a;
            b = cmd[q].b;
            c = cmd[q].c;
            if (c == 'D')
                merge_point(joint[a].F, joint[a].S);
            else if (c == 'Q') {
                divid++;
                int pa = p(a);
                node *tmp = kth(root[pa], b);
                sum += tmp ? tmp->key : 0;
            }else {
                int pa = p(a);
                erase(root[pa], w[a]);
                insert(root[pa], b);
                w[a] = b;
            }
        }
        cout << "Case " << cas++ << ": " << fixed << setprecision(6) << sum / divid << '\n';
    }
    return 0;
}

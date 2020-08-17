/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 14 23:19:59 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
int n;
vector<int> v;
pii changes[200010];
int dis_c[200010];

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

struct bittree {
    int n;
    ll sum[400010];
    bittree(int n) : n(n) {for (int i = 0; i <= n; i++) sum[i] = 0;}
    void add(int i, ll x) {
        while (i <= n) {
            sum[i] += x;
            i += i & -i;
        }
    }
    ll query(int i) {
        ll re = 0;
        while (i) {
            re += sum[i];
            i -= i & -i;
        }
        return re;
    }
};
ll allsum, cnt;
set<ll> fire, light;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b > 0)
            v.emplace_back(b);
        changes[i] = {a, b};
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < n; i++) {
        int b = abs(changes[i].second);
        dis_c[i] = (lower_bound(v.begin(), v.end(), b) - v.begin()) + 1;
    }
    treap<ll> tree;
    int vsz = v.size() + 1;
    bittree bit(vsz);
    for (int i = 0; i < n; i++) {
        int mode = changes[i].first;
        int num = changes[i].second;
        int d_num = dis_c[i];
        if (num > 0) {
            cnt++;
            allsum += num;
            tree.insert(d_num);
            bit.add(d_num, num);
            if (mode == 0)
                fire.insert(d_num);
            else
                light.insert(d_num);
        }else {
            num = -num;
            cnt--;
            allsum -= num;
            tree.erase(d_num);
            bit.add(d_num, -num);
            if (mode == 0)
                fire.erase(d_num);
            else
                light.erase(d_num);
        }
        // calc ans
        ll ans = allsum;
        int cnt_light = light.size();
        if (cnt_light > 0) {
            int mnlight = *light.begin();
            auto kth = tree.kth(cnt - cnt_light);
            if (kth == nullptr) {
                ans += allsum - v[mnlight - 1];
            }else {
                //cout << kth->key << endl;
                if (kth->key < mnlight) {
                    kth = tree.kth(cnt - cnt_light - 1);
                    if (kth == nullptr)
                        ans += allsum - v[mnlight - 1];
                    else
                    ans += allsum - bit.query(kth->key) - v[mnlight - 1];
                }else
                    ans += allsum - bit.query(kth->key);
            }
        }
        cout << ans << endl;
    }
    return 0;
}


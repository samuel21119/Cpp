/*************************************************************************
  > File Name: 263.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Aug 25 12:14:12 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int rand() {
	static int x = 123456789;
	return x += (x << 2) + 1;
}
struct node {
	int key;
	int pri, s, ma;
	node *l, *r;
	node(){l = r = nullptr;}
	node(int i) : key(i) {
		ma = i;
		s = 1;
		pri = rand();
		l = r = nullptr;
	}
	void up() {
		ma = key;
		s = 1;
		if (l)
			s += l->s, ma = max(ma, l->ma);
		if (r)
			s += r->s, ma = max(ma, r->ma);
	}
}*root;
int size(node* o) {
	return o ? o->s : 0;
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
void split(node *o, node *&a, node *&b, int k) {
	if (!o)
		a = b = nullptr;
	else {
		if (k >= size(o->l) + 1) {
			a = o;
			split(o->r, a->r, b, k - size(o->l) - 1);
		}else {
			b = o;
			split(o->l, a, b->l, k);
		}
		o->up();
	}
}
int num;
int n, q;
int a, b, c;
node *p1, *p2, *p3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> q) {
    	root = nullptr;
    	for (int i = 0; i < n; i++) {
    		cin >> a;
    		root = merge(root, new node(a));
    	}
    	while (q--) {
    		cin >> a >> b;
    		p1 = p2 = p3 = nullptr;
    		if (a != 4)
    			cin >> c;
    		if (a == 1) {
    			split(root, p1, p3, b);
    			split(p1, p1, p2, b - 1);
    			delete p2;
    			p2 = new node(c);
    			root = merge(p1, merge(p2, p3));
    		}else if (a == 2) {
    			split(root, p1, p3, c);
    			split(p1, p1, p2, b - 1);
    			p2->up();
    			cout << p2->ma << '\n';
    			root = merge(p1, merge(p2, p3));
    		}else if(a == 3) {
    			split(root, p1, p2, b - 1);
    			root = merge(p1, merge(new node(c), p2));
    		}else {
    			split(root, p1, p3, b);
    			split(p1, p1, p2, b - 1);
    			delete p2;
    			root = merge(p1, p3);
    		}
    	}
    }
    return 0;
}

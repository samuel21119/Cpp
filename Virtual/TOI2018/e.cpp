/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 27 15:00:25 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int input[100001];
int n;
int tree[100000 * 4];
int maketree(int l, int r, int index) {
	if (l == r)
		return tree[index] = input[l];
	int m = (l + r) >> 1;
	int index2 = (index << 1) + 1;
	return tree[index] = min(maketree(l, m, index2), maketree(m + 1, r, index2 + 1));
}
int query(int s, int e, int l, int r, int index) {
	if (l > e || r < s)
		return 1 << 30;
	if (s <= l && r <= e)
		return tree[index];
	int m = (l + r) >> 1;
	int index2 = (index << 1) + 1;
	return min(query(s, e, l, m, index2), query(s, e, m + 1, r, index2 + 1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> input[i];
    maketree(0, n - 1, 0);
    int s, e;
    while (cin >> s >> e)
    	cout << query(s - 1, e - 1, 0, n - 1, 0) + 1 << '\n';
    return 0;
}

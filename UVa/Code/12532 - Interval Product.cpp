/*************************************************************************
  > File Name: 12532 - Interval Product.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jun  1 20:21:02 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
short input[100001];
short tree[262144];
int n, m, Start, End;
int target, change_value;
short make_tree(int l, int r, int index) {
    if (l == r)
        return tree[index] = input[l];
    int mid = (l + r) >> 1;
    int index2 = index << 1;
    return tree[index] = make_tree(l, mid, index2 + 1) * make_tree(mid + 1, r, index2 + 2);
}
short query(int l, int r, int index) {
    if (Start <= l && r <= End)
        return tree[index];
    if (l > End || r < Start)
        return 1;
    int mid = (l + r) >> 1;
    int index2 = index << 1;
    return query(l, mid, index2 + 1) * query(mid + 1, r, index2 + 2);
}
short change(int l, int r, int index) {
    if (l == r && l == target)
        return tree[index] = input[l] = change_value;
    if (target < l || r < target)
        return tree[index];
    int mid = (l + r) >> 1;
    int index2 = index << 1;
    return tree[index] = change(l, mid, index2 + 1) * change(mid + 1, r, index2 + 2);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp1, tmp2;
    char tmpc;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> tmp1;
            if (tmp1 > 0) input[i] = 1;
            else if (tmp1) input[i] = -1;
            else input[i] = 0;
        }
        make_tree(1, n, 0);
        while (m--) {
            cin >> tmpc >> tmp1 >> tmp2;
            if (tmpc == 'C') {
                if (tmp2 > 0) tmp2 = 1;
                else if (tmp2) tmp2 = -1;
                else tmp2 = 0;
                if (input[tmp1] != tmp2) {
                    target = tmp1;
                    change_value = tmp2;
                    change(1, n, 0);
                }
            }
            else {
                Start = tmp1;
                End = tmp2;
                int a = query(1, n, 0);
                if (a > 0)
                    cout << '+';
                else if (a)
                    cout << '-';
                else
                    cout << '0';
            }
        }
        cout << '\n';
    }    
    return 0;
}

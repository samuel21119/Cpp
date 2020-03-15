/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Oct 12 22:29:47 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long t, n, v, l, r, tmp, tmp2, all;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> v >> l >> r;
        all = n / v;
        tmp = l / v;
        if (!(l % v) && tmp)
            tmp--;
        tmp2 = r / v;
        cout << tmp + all - tmp2 << '\n';
    }
    return 0;
}

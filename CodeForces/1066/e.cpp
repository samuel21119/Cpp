/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Oct 12 23:20:44 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m, nm;
long long ans, mod = 998244353, tmp;
char in;
bitset<200010> a, b, c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> in;
        a <<= 1;
        a |= in == '1';
    }
    for (int i = 0; i < m; i++) {
        cin >> in;
        b <<= 1;
        b |= in == '1';
    }
    cout << ans;
    return 0;
}

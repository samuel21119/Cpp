/*************************************************************************
  > File Name: 01513 - Movie collection.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Sep  5 17:57:51 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int bit[200010];
int x[100001];
int n, m;
void init() {
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; i++) {
        x[i] = n - i + 1;
        for (int j = i; j < maxn; j += j & -j)
            bit[j]++;
    }
}
int query(int i) {
    int re = 0;
    while (i)
        re += bit[i], i -= i & -i;
    return re;
}
void modify(int i, int d) {
    while (i < maxn)
        bit[i] += d, i += i & -i;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, a, ans;
    cin >> c;
    while(c--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; i++) {
            cin >> a;
            ans = n - query(x[a]);
            if (ans) {
                modify(x[a], -1);
                modify(x[a] = n + i, 1);
            }
            cout << ans << (i == m ? '\n' : ' ');
        }
    }
    return 0;
}

/*************************************************************************
  > File Name: 10462 - Is There A Second Way Left.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep 23 12:04:45 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
struct L {
    int a, b;
    int v;
    L() {}
    L(int a, int b, int v) : a(a), b(b), v(v) {}
    bool operator< (const L &b) const {
        return v < b.v;
    }
}line[210];
int n, m, parent[110], use[110];
int deep[110];
int find(int i) {
    return i == parent[i] ? i : parent[i] = find(parent[i]);
}
int MST(int remove) {
    for (int i = 0; i <= n + 1; i++)
        parent[i] = i;
    int ans = 0;
    int cnt = 0, a, b;
    for (int i = 0; i < m; i++) {
        if (i == remove)
            continue;
        a = find(line[i].a);
        b = find(line[i].b);
        if (a == b)
            continue;
        parent[b] = a;
        ans += line[i].v;
        if (remove == -1)
            use[cnt] = i;
        cnt++;
    }
    if (cnt >= n - 1)
        return ans;
    return inf;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, a, b, v, nn;
    cin >> t;
    for (int i = 0; i < t; ) {
        cin >> n >> m;
        nn = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> v;
            line[i] = {a, b, v};
        }
        cout << "Case #" << ++i << " : ";
        sort(line, line + m);
        if (MST(-1) == inf) {
            cout << "No way\n";
            continue;
        }
        int ans = inf;
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, MST(use[i]));
        }
        if (ans == inf)
            cout << "No second way\n";
        else
            cout << ans << '\n';
    }
    return 0;
}

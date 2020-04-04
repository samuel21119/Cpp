/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Apr  3 22:46:50 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[200010];
int b1[200010], b2[200010];
int u1[200010], u2[200010];
void add(int i, int dx, int* bit) {
    while (i <= n) {
        bit[i] += dx;
        i += i & -i;
    }
}
int sum(int i, int *bit) {
    int re = 0;
    while (i > 0) {
        re += bit[i];
        i -= i & -i;
    }
    return re;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i <= n; i++) {
            b1[i] = b2[i] = u1[i] = u2[i] = 0;
        }
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 1; i < n; i++) {
            if (!u2[in[i]])
                add(in[i], 1, b2);
            u2[in[i]]++;
        }
        u1[in[0]] = 1;
        add(in[0], 1, b1);
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            if (sum(i, b1) == i && sum(n - i, b2) == n - i)
                ans.emplace_back(i);
            if (--u2[in[i]] == 0)
                add(in[i], -1, b2);
            if (u1[in[i]]++ == 0)
                add(in[i], 1, b1);
        }
        cout << ans.size() << '\n';
        for (int i : ans)
            cout << i << ' ' << n - i << '\n';
    }
    return 0;
}

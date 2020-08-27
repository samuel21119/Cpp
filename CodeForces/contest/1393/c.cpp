/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Aug 27 14:34:10 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[100010];
int cnt[100010];
struct pii {
    int x, y;
    pii() {}
    pii(int a, int b) {
        x = a, y = b;
    }
    bool operator< (const pii &b) const {
        if (y == b.y)
            return x > b.x;
        return y > b.y;
    }
};
bool check(int x) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
        cnt[in[i]]++;
    set<pii> s;
    for (int i = 1; i <= n; i++) {
        if (cnt[i])
            s.insert({i, cnt[i]});
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (i >= x && cnt[v[i - x]]) {
            s.insert({v[i - x], cnt[v[i - x]]});
        }
        if (s.empty())
            return 0;
        pii now = *s.begin();
        v.emplace_back(now.x);
        cnt[now.x]--;
        s.erase(s.begin());
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        int l = 0, r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (check(m))
                l = m;
            else
                r = m;
        }
        cout << l - 1 << '\n';
    }
    return 0;
}

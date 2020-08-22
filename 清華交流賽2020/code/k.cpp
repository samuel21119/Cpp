#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 998244353LL;
struct pii {
    int x, y;
    pii() {}
    pii(int a, int b) {
        x = a, y = b;
    }
    bool operator< (const pii &b) const {
        if (x == b.x)
            return y < b.y;
        return x < b.x;
    }
}in[100010];
ll mypow(ll x, ll cnt) {
    if (cnt == 0)
        return 1;
    if (cnt == 1)
        return x;
    ll t = mypow(x, cnt / 2);
    t = t * t % mod;
    if (cnt & 1)
        t = t * x % mod;
    return t;
}
int n, m;
int pos[100010];
ll ans;
vector<int> v;
set<int> X[400010], Y[400010];
bool candig[400010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a);
        v.emplace_back(b);
        in[i] = {a, b};
    }
    for (int i = 0; i < m; i++) {
        cin >> pos[i];
        v.emplace_back(pos[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int sz = v.size();
    for (int i = 0; i < n; i++) {
        int st = lower_bound(v.begin(), v.end(), in[i].x) - v.begin() + 1;
        int end = lower_bound(v.begin(), v.end(), in[i].y) - v.begin() + 1;
        X[st].insert(i);
        Y[end + 1].insert(i);
    }
    for (int i = 0; i < m; i++) {
        candig[lower_bound(v.begin(), v.end(), pos[i]) - v.begin() + 1] = 1;
    }
    sz += 3;
    set<int> A, B;
    for (int i = 1; i < sz; i++) {
        for (auto i : Y[i]) {
            if (A.count(i))
                A.erase(i);
            else
                B.erase(i);
        }
        for (auto i : X[i]) {
            B.insert(i);
        }
        if (candig[i]) {
            ans = (ans + mypow(2, A.size() + B.size()) + mod - mypow(2, A.size())) % mod;
            for (auto i : B) {
                A.insert(i);
            }
            B.clear();
        }
    }
    cout << ans << '\n';
    return 0;
}

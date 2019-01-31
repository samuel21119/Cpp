#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int change[3000010];
pair<int, int> tmp[6000000];
int use[3000010];
ll A;
int n, m;
int id = 1, times = 1;
int f(ll x) {
    return (x ^ A) % n;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll p = 1LL << 32;
    cout << p;
    cin >> n >> m >> A;
    for (int i = 0; i < 6000000; i++)
        tmp[i].second = 0;
    while (m--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int q;
            ll in;
            cin >> q;
            for (int i = 0; i < q; i++) {
                cin >> in;
                int t = f(in);
                if (use[t] == times)
                    continue;
                if (tmp[change[t]].second != times) {
                    tmp[change[t]].first = id++;
                    tmp[change[t]].second = times;
                }
                change[t] = tmp[change[t]].first;
                use[t] = times;
            }
            assert(id < 6000000);
            times++;
        }else {
            ll a, b;
            cin >> a >> b;
            int fa = change[f(a)];
            int fb = change[f(b)];
            if (fa == fb)
                A = (22695477 * A + 1) % p;
            else
                A = (69069 * A + 1) % p;
        }
    }
    cout << A << '\n';
}

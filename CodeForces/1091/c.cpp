#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000000001;
bitset<maxn> u;
ll gcd(ll a, ll b) {
    while (a % b && b % a)
        a < b ? b %= a : a %= b;
    return min(a, b);
}
ll s(ll n, ll k) {
    if (k == n)
        return 1;
    return (k * (n / k - 1) * (n / k) / 2 + n / k);
}
vector<ll> d;
int main(){
    ll n, a;
    cin >> n;
    a = sqrt(n) + 1;
    u[1] = u[n] = 1;
    cout << "1 ";
    for (ll i = 2; i < a; i++) {
        ll g = gcd(i, n);
        if (u[g])
            continue;
        d.emplace_back(s(n, g));
        if (n != g * g)
            d.emplace_back(s(n, n / g));
        u[g] = 1;
    }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (ll i : d)
        cout << i << ' ';
    cout << (n + 1) * n / 2 << '\n';
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, x, y;
ll gcd(ll a, ll b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> x >> y;
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    cout << min(a / x, b / y) << '\n';
}
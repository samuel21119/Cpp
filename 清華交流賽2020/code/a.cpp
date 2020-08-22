#include <bits/stdc++.h>
using namespace std;

using ll = long long;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n = s.length();
    ll t = 0;
    if (n % 2 == 0) {
        ll a, b; a = b = 0;
        for (int i = 0; i < n / 2; i++)
            a = a * 10 + s[i] - '0';
        for (int i = n / 2; i < n; i++)
            b = b * 10 + s[i] - '0';
        t = min(a, b);
        t = max(t, a - 1);
        n--;
    }
    n /= 2;
    ll s2 = 0;
    while (n > 0) {
        s2 = s2 * 10 + 9;
        n--;
    }
    cout << max(t, s2);
    return 0;
}
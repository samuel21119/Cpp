/*************************************************************************
  > File Name: d2.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 19 23:18:46 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 99999989;
const ll mul = 9487;
ll haL[2000010], haR[2000010];
ll mul2[2000010];
ll p(ll a, ll cnt) {
    if (cnt == 0)
        return 1;
    if (cnt == 1)
        return a;
    int m = cnt / 2;
    ll t = p(a, m);
    return t * t % mod * (cnt & 1 ? a : 1) % mod;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mul2[0] = 1;
    for (int i = 1; i < 2000001; i++)
        mul2[i] = mul2[i - 1] * mul % mod;
    int t;
    cin >> t;
    while (t--) {
        string s;
        string s2;
        cin >> s;
        int n = s.length();
        int l, r;
        int lr, rl;
        lr = rl = -1;
        l = 0; r = n - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
                continue;
            }
            haL[l] = s[l];
            for (int a = l + 1; a < r; a++) {
                haL[a] = (haL[a - 1] * mul + s[a]) % mod;
            }
            ll hash = 0;
            ll b = r - 1;
            for (int a = r - 1; a >= l; a--) {
                hash = (hash * mul + s[a]) % mod;
                while (a <= b && hash != haL[l + (b - a)]) {
                    hash = (hash - s[b] * mul2[b - a] % mod + mod) % mod;
                    b--;
                }
                if (a <= b) {
                    int len = b - a;
                    if (haL[l + len] == hash && (l + len == a || l + len + 1 == a)) {
                        lr = b;
                        break;
                    }
                }
            }

            haR[r] = s[r];
            for (int a = r - 1; a > l; a--) {
                haR[a] = (haR[a + 1] * mul + s[a]) % mod;
            }
            hash = 0;
            b = l + 1;
            for (int a = l + 1; a <= r; a++) {
                hash = (hash * mul + s[a]) % mod;
                while (b <= a && hash != haR[r - (a - b)]) {
                    hash = (hash - s[b] * mul2[a - b] % mod + mod) % mod;
                    b++;
                }
                if (b <= a) {
                    int len = a - b;
                    if (haR[r - len] == hash && (r - len == a || r - len - 1 == a)) {
                        rl = b;
                        break;
                    }
                }
            }
            break;
        }
        //cout << l << ' '<<r<<' '<<rl<<' '<<lr<<endl;
        if (r <= l) {
            cout << s << '\n';
        }else {
            string b;
            for (int i = 0; i < l; i++)
                b += s[i];
            if (lr != -1 && ((rl == -1) || (lr - l > r - rl))) {
                for (int i = l; i <= lr; i++)
                    b += s[i];
            }else if (rl != -1)
                for (int i = rl; i <= r; i++)
                    b += s[i];
            for (int i = r + 1; i < n; i++)
                b += s[i];
            if (b.empty())
                cout << s[0];
            else
                cout << b;
            cout << '\n';
        }
    }
    return 0;
}

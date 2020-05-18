/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Apr  8 22:57:02 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll in[200010];
set<ll> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    ll ans = 0;
    ll sum = 0;
    ll last = -1;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            sum = 0;
            last = i;
            s.clear();
            continue;
        }
        if (s.find(-sum - in[i]) == s.end()) {
            ll t = i - last;
            ans += t;
            s.insert(-sum);
            sum += in[i];
        }else {
            ll s2 = 0;
            int t = i - 1;
            while (t > last ) {
                s2 += in[t];
                if (s2 == -in[i])
                    break;
                t--;
            }
            s.clear();
            last = t;
            s2 = 0;
            for (int j = t + 1; j <= i; j++) {
                s.insert(-s2);
                s2 += in[j];
            }
            sum = s2;
            ans += i - last;
        }

    }
    cout << ans << '\n';
    return 0;
}

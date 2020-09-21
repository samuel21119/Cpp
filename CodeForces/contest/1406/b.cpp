/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep 17 15:41:21 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll in[100010];
pair<int, int> in2[100010];

ll cnt(int negCnt) {
    int neg = 0;
    int pos = 0;
    int zero = 0;
    ll re = 1;
    int posCnt = 5 - negCnt;
    if (negCnt & 1) {
        for (int i = 0; i < n; i++) {
            ll now = in[in2[i].second];
            if (now < 0) {
                if (++neg <= negCnt)
                    re *= now;
            }else if (now > 0) {
                if (++pos <= posCnt)
                    re *= now;
            }else
                zero++;
        }
    }else {
        for (int i = n - 1; i >= 0; i--) {
            ll now = in[in2[i].second];
            if (now < 0) {
                if (++neg <= negCnt)
                    re *= now;
            }else if (now > 0) {
                if (++pos <= posCnt)
                    re *= now;
            }else
                zero++;
        }
    }

    if (neg >= negCnt && pos >= posCnt)
        return re;
    if (zero)
        return 0;
    return -(1LL << 60);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
            in2[i] = {abs(in[i]), i};
        }
        sort(in2, in2 + n);
        ll ans = -(1LL << 60);
        for (int i = 0; i <= 5; i++)
            ans = max(ans, cnt(i));
        cout << ans << '\n';
    }
    return 0;
}

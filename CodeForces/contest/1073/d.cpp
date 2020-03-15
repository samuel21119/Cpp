/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Oct 25 23:23:17 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll t;
ll in[200010];
ll sum, cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        if (in[i] > t) {
            i--;
            n--;
            continue;
        }
        sum += in[i];
    }
    if (!sum) {
        cout << 0;
        return 0;
    }
    cnt = t / sum * n;
    t %= sum;
    while (t > 0) {
        ll cnt2 = 0;
        ll sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (t < in[i])
                continue;
            t -= in[i];
            sum2 += in[i];
            cnt2++;
        }
        if (!cnt2)
            break;
        cnt += cnt2 * (1 + t / sum2);
        t -= t / sum2 * cnt2;
    }
    cout << cnt;
    return 0;
}

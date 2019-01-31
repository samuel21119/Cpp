/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep  9 15:06:22 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll in[200001];
int main() {
    ll n, a[100001], s, f, p, cnt = 0, po, ans;
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        in[i] = in[i - 1] + a[i];
    }
    cin >> s >> f;
    po = s;
    p = f - s;  //P(p)
    for (int i = n + 1; i <= n << 1; i++)
        in[i] = in[i - 1] + a[i - n];

    for (int i = 0; i < n; i++) {
        ll now = s - i;
        if (now < 1)
            now += n;
        if (in[i + p] - in[i] == cnt)
            ans = min(ans, now);
        else if (in[i + p] - in[i] > cnt)
            cnt = in[i + p] - in[i],  ans = now;
    }
    cout << ans << '\n';
    return 0;
}

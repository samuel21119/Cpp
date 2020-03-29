/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 19 23:08:59 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
ll in[200010];
ll ans = 1;
ll mn;
ll cnt;
int n, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    for (int i = 0; i < k; i++)
        cnt += n - i;
    cout << cnt << ' ';
    mn = n - k + 1;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] < mn)
            continue;
        in[cnt++] = i;
    }
    for (int i = 1; i < k; i++)
        ans = (ans *(in[i] - in[i - 1])) % mod;
    cout << ans;
    return 0;
}

/*************************************************************************
  > File Name: f.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar  3 15:24:39 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 99999989;
const ll mul = 9487;
int n;
bool in[200010];
int sum[200010];
vector<int> v;
ll ha[2][200010];
ll dp[200010];
ll calc(int times) {
    if (times <= 0)
        return dp[0] = 1;
    if (dp[times])
        return dp[times];
    return dp[times] = calc(times - 1) * mul % mod;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        char a;
        cin >> a; a -= '0';
        in[i] = a;
        sum[i] = !a + sum[i - 1];
        if (!a)
            v.emplace_back(i);
    }
    int len = v.size();
    ha[0][0] = 0;
    ha[1][0] = 0;
    ll m = mul;
    for (int i = 1; i < len; i++) {
        ha[0][i] = (ha[0][i - 1] * m + (v[i] & 1)) % mod;
        ha[1][i] = (ha[1][i - 1] * m + !(v[i] & 1)) % mod;
    }
    ha[0][len] = ha[0][len - 1];
    int t;
    cin >> t;
    while (t--) {
        int l1, l2, m;
        cin >> l1 >> l2 >> m;
        if (l2 < l1)
            swap(l1, l2);
        if (sum[l1 + m - 1] - sum[l1 - 1] != sum[l2 + m - 1] - sum[l2 - 1]) {
            cout << "No" << '\n';
            continue;
        }
        ll ptrx1 = lower_bound(v.begin(), v.end(), l1) - v.begin();
        ll ptrx2 = ptrx1 + sum[l1 + m - 1] - sum[l1 - 1] - 1;
        ll ptry1 = lower_bound(v.begin(), v.end(), l2) - v.begin();
        ll ptry2 = ptry1 + sum[l1 + m - 1] - sum[l1 - 1] - 1;
        int t1 = (l1 & 1);
        int t2 = (l2 & 1);
        ll hash1 = ha[t1][ptrx2] - ha[t1][ptrx1 - 1] * calc(ptrx2 - ptrx1 + 1) % mod;
        ll hash2 = ha[t2][ptry2] - ha[t2][ptry1 - 1] * calc(ptry2 - ptry1 + 1) % mod;
        if (hash1 < 0) hash1 += mod;
        if (hash2 < 0) hash2 += mod;
        //cout << hash1 << ' ' << hash2 << ' ' << ptrx1 << ' ' << ptry1 << ' ' << ptrx2 << ' ' << ptry2 << ' ' << t1 << ' ' << t2 <<'\n';
        if (hash1 == hash2)
            cout << "Yes";
        else
            cout << "No";
        cout << '\n';
    }
    return 0;
}

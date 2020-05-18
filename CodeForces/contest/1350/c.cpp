/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun May 17 22:32:22 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, ans = 1;
bool p[200010];
vector<int> prime;
int po(int x, int i) {
    if (i <= 0)
        return 1;
    else if (i == 1)
        return x;
    int m = i / 2;
    int re = po(x, m);
    re = re * re * (m % 2 ? x : 1);
    return re;
}
int mn1[200010];
int mn2[200010];
int cnt[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    prime.emplace_back(2);
    for (int i = 3; i <= 200000; i += 2) {
        if (p[i])
            continue;
        prime.emplace_back(i);
        for (int j = i * 2; j <= 200000; j += i)
            p[j] = 1;
    }
    cout << prime.size();
    for (int i = 0; i < 200010; i++)
        mn1[i] = mn2[i] = 40;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, j;
        cin >> t;
        vector<pair<int, int>> v;
        for (j = 0; prime[j] * prime[j] <= t; j++) {
            int cur = prime[j];
            int cnt = 0;
            if (t % cur)
                continue;
            while (t % cur == 0) {
                t /= cur;
                cnt++;
            }
            v.push_back({j, cnt});
        }
        if (t > 1) {
            v.push_back({lower_bound(prime.begin(), prime.end(), t) - prime.begin(), 1});
        }
        for (auto i : v) {
            int a = i.first;
            int b = i.second;
            if (b <= mn1[a]) {
                mn2[a] = mn1[a];
                mn1[a] = b;
            }else
                mn2[a] = min(mn2[a], b);
            cnt[a]++;
        }
    }
    for (int i = 0; i < (int)prime.size(); i++) {
        int add = mn2[i];
        if (n - cnt[i] == 1)
            add = mn1[i];
        else if (n - cnt[i] >= 2)
            add = 0;
        ans *= po(prime[i], add);
    }
    cout << ans << '\n';
    return 0;
}

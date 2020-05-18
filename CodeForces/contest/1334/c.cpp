/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Apr 10 22:52:40 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
pair<ll, ll> in[300010];
ll sum[300010];
ll need[300010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            ll a, b;
            cin >> a >> b;
            in[i] = {a, b};
        }
        in[0] = in[n];
        need[0] = in[0].first;
        for (int i = 1; i < n; i++) {
            if (in[i - 1].second >= in[i].first)
                continue;
            need[0] += in[i].first - in[i - 1].second;
        }
        need[n] = need[0];
        //cout << need[n] << '\n';
        for (int i = n - 1; i; i--) {
            need[i] = in[i].first + need[i + 1] - in[i + 1].first;
            if (in[i].second >= in[i + 1].first) {
            }else
                need[i] += in[i + 1].first - in[i].second;

            if (in[i - 1].second < in[i].first) {
                need[i] -= in[i].first - in[i - 1].second;
            }
            //cout << need[i] << '\n';
        }
        cout << *min_element(need, need + n) << '\n';
    }
    return 0;
}

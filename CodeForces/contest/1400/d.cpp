/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Aug 25 23:48:12 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int t;
int n;
int in[3010];
int cnt[3010][3010];
ll tmp[3010], tmp2[3010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> in[i];
        for (int i = 0; i <= n; i++) {
            memset(cnt[i], 0, (n + 1) * sizeof(int));
        }
        for (int i = 1; i <= n; i++) {
            cnt[i][in[i]] = 1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cnt[i][j] += cnt[i - 1][j];

        ll ans = 0;
        for (int i = 1; i < n; i++) {
            ll add = 0;
            for (int j = 1; j <= n; j++) {
                tmp[j] = cnt[n][j] - cnt[i][j];
                tmp2[j] = 0;
            }
            for (int j = i + 2; j < n; j++) {
                int now = in[j];
                int prev = in[j - 1];
                add -= tmp[prev] * tmp2[prev];
                tmp[prev]--;
                tmp2[prev]++;
                add += tmp[prev] * tmp2[prev];
                if (in[j] == in[i]) {

                    add -= tmp[now] * tmp2[now];
                    tmp[now]--;
                    add += tmp[now] * tmp2[now];
                    
                    ans += add;


                    add -= tmp[now] * tmp2[now];
                    tmp[now]++;
                    add += tmp[now] * tmp2[now];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

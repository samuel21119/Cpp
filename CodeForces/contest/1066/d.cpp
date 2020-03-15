/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Oct 12 23:51:49 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans, tmp;
int in[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        in[i] += in[i - 1];
    }
    in[n + 1] = 1 << 30;
    for (int i = 1; i <= n; i++) {
        int a = i;
        int cnt = 0;
        for (int j = 0; j < m && a < n; j++) {
            tmp = in[a - 1] + k;
            if (tmp < in[a])
                break;
            int nxt = lower_bound(in + 1, in + n + 1, tmp) - in;
            if (in[nxt] > tmp)
                nxt--;
            cnt += nxt - a + 1;
            //cout << tmp << ' ' <<  nxt << '\n';
            a = nxt + 1;
        }
        //cout << '\n';
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}

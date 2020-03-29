/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Mar 22 20:21:36 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int h, w, k;
int in[11][1010];
int sum[11][1010];
int ans;
void check(int x) {
    vector<int> v;
    v.emplace_back(0);
    int cnt = 0;
    for (int j = 1; j < h; j++) {
        int a = (x >> (j - 1)) & 1;
        if (a)
            v.emplace_back(j);
        cnt += a;
    }
    v.emplace_back(h);
    int last = 0;
    for (int i = 1; i <= w; i++) {
        bool to_cut = 0;
        for (int j = 1; j < (int)v.size(); j++) {
            int s = sum[v[j]][i] - sum[v[j - 1]][i] - sum[v[j]][last] + sum[v[j - 1]][last];
            int s2 = sum[v[j]][i] - sum[v[j]][i - 1] - sum[v[j - 1]][i] + sum[v[j - 1]][i - 1];
            if (s2 > k)
                return;
            //cout << v[j] << ' ' << v[j - 1] << ' ' << i << ' ' << last << ' '<< s << '\n';
            to_cut |= s > k;
        }
        if (to_cut) {
            last = i - 1;
            cnt++;
        }
    }
    ans = min(ans, cnt);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w >> k;
    ans = 1e9;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            char a;
            cin >> a;
            in[i][j] = a == '1';
            sum[i][j] = in[i][j] - sum[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1];
        }
    int mx = 1 << (h - 1);
    for (int i = 0; i < mx; i++) {
        check(i);
    }
    cout << ans << '\n';
    return 0;
}

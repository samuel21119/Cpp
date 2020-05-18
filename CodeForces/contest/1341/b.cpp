/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Apr 23 22:50:20 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k;
int in[200010];
int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        vector<int> v;
        for (int i = 1; i < n - 1; i++) {
            if (in[i] > in[i - 1] && in[i] > in[i + 1])
                v.emplace_back(i);
        }
        int mx = -1;
        int l = 0;
        for (int i = 0; i < n - 1; i++) {
            int now = i;
            int end = now + k - 1;
            int t = lower_bound(v.begin(), v.end(), end) - v.begin();
            int t2 = upper_bound(v.begin(), v.end(), now) - v.begin();
            int tmp = t - t2;
            if (tmp > mx) {
                mx = tmp;
                l = now + 1;
            }
        }
        cout << mx + 1 << ' ' << l << '\n';
    }
    return 0;
}

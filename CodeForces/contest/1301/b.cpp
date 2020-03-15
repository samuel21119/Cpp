/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Feb 14 10:57:31 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int in[10000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        int mx, mn, md;
        mx = -1;
        mn = 100000000;
        md = -1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && in[i] >= 0 && in[i - 1] >= 0)
                md = max(md, abs(in[i] - in[i - 1]));
            if (in[i] >= 0)
                continue;
            if (i > 0 && in[i - 1] >= 0) {
                mx = max(mx, in[i - 1]);
                mn = min(mn, in[i - 1]);
            }
            if (i + 1 < n && in[i + 1] >= 0) {
                mx = max(mx, in[i + 1]);
                mn = min(mn, in[i + 1]);
            }
        }
        cout << max(md, (mx - mn + 1) / 2) << ' ' << (mx + mn) / 2 << '\n';
    }
    return 0;
}

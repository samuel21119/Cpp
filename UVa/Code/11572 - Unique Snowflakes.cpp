/*************************************************************************
  > File Name: 11572 - Unique Snowflakes.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Nov 30 21:23:02 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int c, n;
vector<int> in, in2;
int use[1000000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    for (int t = 1; t <= c; t++) {
        cin >> n;
        if (!n) {
            cout << "0\n";
            continue;
        }
        in.resize(n);
        in2.resize(n);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            in[i] = in2[i] = a;
        }
        sort(in2.begin(), in2.end());
        in2.resize(unique(in2.begin(), in2.end()) - in2.begin());
        int prev, ans;
        prev = 0; ans = 1;
        for (int i = 0; i < n; i++) {
            int now = lower_bound(in2.begin(), in2.end(), in[i]) - in2.begin();
            in[i] = now;
            if (use[now] == t) {
                ans = max(ans, i - prev);
                while (in[prev] != now)
                    use[in[prev++]] = 0;
                prev++;
                continue;
            }
            ans = max(ans, i - prev);
            use[now] = t;
        }
        cout << max(ans, n - prev) << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 21 22:53:59 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
int n;
int in[100010];
int gcd(int a, int b) {
    if (b)
        return gcd(b, a % b);
    return a;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        deque<int> v;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        int mn = *min_element(in, in + n);
        for (int i = 0; i < n; i++) {
            if (in[i] % mn == 0)
                in[i] = 0, v.emplace_back(in[i]);
        }
        sort(v.begin(), v.end());
        int pre = -1;
        bool ans = 1;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                in[i] = v.front();
                v.pop_front();
            }
            if (pre <= in[i])
                pre = in[i];
            else
                ans = 0;
        }
        cout << (ans ? "YES":"NO") << '\n';
    }
    return 0;
}

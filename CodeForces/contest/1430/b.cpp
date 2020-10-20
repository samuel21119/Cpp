/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 14 20:28:38 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, k;
int in[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        sort(in, in + n);
        ll sum = in[n - 1];
        for (int i = 0; i < k; i++) {
            sum += in[n - 2 - i];
        }
        cout << sum << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar  4 22:29:24 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        int in[1000];
        cin >> n >> m;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
            sum += in[i];
        }
        if (sum <= m) {
            cout << sum << '\n';
            continue;
        }
        cout << m << '\n';
    }
    return 0;
}

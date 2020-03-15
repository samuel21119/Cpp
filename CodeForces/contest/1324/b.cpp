/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 12 21:14:29 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int in[5010];
int have[5010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool ans = 0;
        memset(have, 0, sizeof(have));
        for (int i = 1; i <= n; i++) {
            cin >> in[i];
            if (!have[in[i]])
                have[in[i]] = i;
            else
                ans |= i - have[in[i]] > 1;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep 10 14:43:34 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t;
int n, k;
char in[300010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        bool ans = 1;
        int cnt1, cnt2;
        cnt1 = cnt2 = 0;
        for (int i = 0; i < k; i++) {
            char syb = in[i];
            for (int j = i + k; j < n; j += k) {
                if (syb == '?')
                    syb = in[j];
                else if (in[j] != '?')
                    ans &= syb == in[j];
            }
            in[i] = syb;
        }
        for (int i = 0; i < k; i++) {
            if (in[i] == '1')
                cnt1++;
            else if (in[i] == '0')
                cnt2++;
        }
        cout << (ans && (max(cnt1, cnt2) <= k / 2) ? "YES" : "NO") << '\n';
    }
    return 0;
}

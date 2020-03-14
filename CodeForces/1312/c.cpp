/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 10 14:23:22 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, k;
ll in[35];
bool used[64];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(used, 0, sizeof(used));
        cin >> n >> k;
        bool ans = 1;
        for (int i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            for (int i = 0; tmp; i++) {
                if (tmp % k) {
                    if (used[i] || tmp % k != 1)
                        ans = 0;
                    used[i] = 1;
                }
                tmp /= k;
            }
        }
        if (ans)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
    return 0;
}

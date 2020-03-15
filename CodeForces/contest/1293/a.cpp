/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan 20 09:30:04 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t;
int n, s, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s >> k;
        set<int> se;
        for (int i = 0; i < k; i++) {
            int t;
            cin >> t;
            se.insert(t);
        }
        int cnt = 0;
        for (int i = 0; i <= k + 1; i++) {
            int up = s + i;
            int down = s - i;
            if (up <= n) {
                if (se.find(up) == se.end()) {
                    cout << cnt << '\n';
                    break;
                }
            }
            if (down > 0) {
                if (se.find(down) == se.end()) {
                    cout << cnt << '\n';
                    break;
                }
            }
            cnt++;
        }

    }
    return 0;
}

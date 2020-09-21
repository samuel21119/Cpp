/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep 17 15:38:50 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int cnt[110];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int A, B;
        A = B = 0;
        for (int i = 0; i <= 101; i++) {
            if (cnt[i] < 2) {
                A = i;
                break;
            }
        }
        for (int i = 0; i <= 101; i++) {
            if (!cnt[i]) {
                B = i;
                break;
            }
        }
        cout << A + B << '\n';
    }
    return 0;
}

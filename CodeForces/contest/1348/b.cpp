/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue May  5 21:22:23 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k;
int used[110];
int cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<int> v;
        cin >> n >> k;
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (!used[x]) {
                used[x] = 1;
                cnt++;
                v.emplace_back(x);
            }
        }
        if ((int)v.size() <= k) {
            while (v.size() != k)
                v.emplace_back(1);
            sort(v.begin(), v.end());
            cout << v.size() * n << '\n';
            while (n--) {
                for (int i : v)
                    cout << i << ' ';
            }
        }else
            cout << -1;
        cout << '\n';
    }
    return 0;
}

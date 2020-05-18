/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Apr 12 22:12:45 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        sort(in, in + n);
        int l = 0;
        int r = n - 1;
        bool last = 1;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (last) {
                v.emplace_back(in[l++]);
                last = 0;
            }else {
                v.emplace_back(in[r--]);
                last = 1;
            }
        }
        for (int i = (int)v.size() - 1; i >= 0; i--)
            cout << v[i] << ' ';
        cout << '\n';
    }
    return 0;
}

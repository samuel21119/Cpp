/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep 10 14:30:57 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int in[110];
int ans[110];
bool vis[110];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        while (n--)
            cout << in[n] << ' ';
        cout << '\n';
    }
    return 0;
}

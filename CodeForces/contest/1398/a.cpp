/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 14 22:36:24 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int mx;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        mx = in[n - 1];
        if (in[0] + in[1] <= mx) {
            cout << "1 2 " << n << '\n';
        }else
            cout << -1<<'\n';
    }
    return 0;
}

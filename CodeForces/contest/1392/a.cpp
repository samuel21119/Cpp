/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 17 18:04:18 2020
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
        for (int i = 0; i < n; i++)
            cin >> in[i];
        sort(in, in + n);
        cout << (in[0] == in[n - 1] ? n : 1) << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 19 22:42:27 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, mx;
int b[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++) {
        cout << b[i] + mx << ' ';
        mx = max(mx, b[i] + mx);
    }
    return 0;
}

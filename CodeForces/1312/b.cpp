/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 10 14:21:12 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int in[1000];
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        sort(in, in + n);
        for (int i = n - 1; i >= 0; i--) {
            cout << in[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Feb 11 13:59:02 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t, n;
int in[200000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int nn = n + n;
        for (int i = 0; i < nn; i++)
            cin >> in[i];
        sort(in, in + nn);
        cout << in[n] - in[n - 1] << '\n';
    }
    return 0;
}

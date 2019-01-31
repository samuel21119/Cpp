/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Sep 21 23:14:29 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}
int in[300001], g[300001];
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in, in + n);
    g[n - 1] = in[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        g[i] = gcd(g[i + 1], in[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        //cout << g[i] << ' ';
        if (g[i + 1] > in[i]) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}

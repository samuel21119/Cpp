/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Mar 12 21:29:30 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010];
int b[200010];
int s1[200010];
int s2[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++) {
        s1[i] = a[i] - b[i];
        s2[i] = b[i] - a[i];
    }
    sort(s1, s1 + n);
    for (int i = 0; i < n; i++) {
        ans += (n - (upper_bound(s1, s1 + n, b[i] - a[i]) - s1));
        ans -= a[i] > b[i];
    }
    cout << ans / 2 << '\n';
    return 0;
}

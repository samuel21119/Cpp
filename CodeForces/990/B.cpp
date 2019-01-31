/*************************************************************************
  > File Name: B.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jun 10 18:18:15 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int a[200001];
int cnt[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, ans;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a, a + n);
    ans = n;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i] && a[i - 1] + k >= a[i])
            ans -= cnt[a[i - 1]];
    }
    cout<< ans << '\n';
    return 0;
}

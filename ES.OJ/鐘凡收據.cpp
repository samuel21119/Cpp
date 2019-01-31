/*************************************************************************
  > File Name: 鐘凡收據.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun May 20 09:37:31 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
long long x[100002], y[100002], ans[100002];
pair<int, int> a[100002];
int n, q;

void binsearch(int l, int r, int Nl, int Nr) {
    if (l > r)
        return;
    int m = (l + r) >> 1;
    pair<long long, int> Max; Max = {-1E16, 0};
    for (int i = Nl; i <= Nr; i++)
        Max = max(Max, {a[m].first * y[i] - x[i], i});
    ans[a[m].second] = Max.first;
    binsearch(l, m - 1, Nl, Max.second);
    binsearch(m + 1, r, Max.second, Nr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    x[0] = y[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        x[i] += x[i - 1];
        y[i] += y[i - 1];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + q);
    binsearch(0, q - 1, 0, n);
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return 0;
}

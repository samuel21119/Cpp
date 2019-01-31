/*************************************************************************
  > File Name: 11300 - Spreading.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Sep 11 16:34:22 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll in[1000001], sum, avg, mid, ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
            sum += in[i];
            in[i] = sum;
        }
        avg = sum / n;
        for (int i = 0; i < n - 1; i++)
            in[i] = in[i] - (i + 1) * avg;
        sort(in, in + n - 1);
        mid = in[(n - 1) >> 1];
        ans = abs(mid);
        for (int i = 0; i < n - 1; i++)
            ans += abs(in[i] - mid);
        cout << ans << '\n';
    }
    return 0;
}

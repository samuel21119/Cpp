/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed 06 Feb 2019 09:54:58 AM CST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll in[300010];
ll sum;
ll p(ll a) {
    return a * a;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in, in + n);
    for (int i = 0; i < n / 2; i++)
        sum += p(in[i] + in[n - i - 1]);
    cout << sum << '\n';
    return 0;
}

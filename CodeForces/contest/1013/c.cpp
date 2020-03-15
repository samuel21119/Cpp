/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 22 20:29:31 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll in[200010];
int n, n2;
ll ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    n2 = n * 2;
    for (int i = 0; i < n2; i++)
        cin >> in[i];
    sort(in, in + n2);
    ans = (in[n - 1] - in[0]) * (in[n2 - 1] - in[n]);
    for (int i = 1; i < n; i++)
        ans = min(ans, (in[n - 1 + i] - in[i]) * (in[n2 - 1] - in[0]));
    cout << ans << '\n';
    return 0;
}

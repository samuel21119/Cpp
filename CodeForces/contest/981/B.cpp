/*************************************************************************
  > File Name: Businessmen Problems.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun May 27 23:14:09 2018
*************************************************************************/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b) {
    if (a > b)
        return a;
    return b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll ans;
    int in1, in2;
    while (cin >> n) {
        ans = 0;
        map<int, ll> total;
        while (n--) {
            cin >> in1 >> in2;
            total[in1] = in2;
            ans += in2;
        }
        cin >> n;
        while (n--) {
            cin >> in1 >> in2;
            ans = ans - total[in1] + max(total[in1], in2);
        }
        cout << ans << '\n';
    }
    return 0;
}

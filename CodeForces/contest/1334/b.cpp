/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Apr 10 22:46:58 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, x;
ll in[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll sum = 0;
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
            sum += in[i];
        }
        sort(in, in + n);
        int ans;
        for (ans = 0; ans < n; ans++) {
            int cnt = n - ans;
            if (sum >= x * cnt)
                break;
            sum -= in[ans];
        }
        cout << n - ans << '\n';
    }
    return 0;
}

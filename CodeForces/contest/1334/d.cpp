/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Apr 11 00:03:52 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        ll sum = 1, S;
        int I = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n)
                sum++;
            else
                sum += (n - i) * 2;
            if (sum < l)
                continue;
            I = i;
            break;
        }
        S = sum -= (n - I) * 2;
        //cout << I << ' ' << sum << endl;
        vector<int> v;
        while (S <= r) {
            for (int i = I + 1; i <= n; i++) {
                v.emplace_back(I);
                v.emplace_back(i);
            }
            if (I < n)
                S += (n - I++) * 2;
            else
                S++;
        }
        v.emplace_back(1);
        int start = l - sum;
        int cnt = r - l + 1;
        for (int i = start; cnt; cnt--, i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar 28 10:23:24 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
char out[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll a = sqrt(k * 2);
        ll b;
        if (a * (a + 1) >= 2 * k) {
            b = k - a * (a - 1) / 2 - 1;
        }else {
            a++;
            b = a - 1 - (a * (a + 1) / 2) + k;
        }
        for (int i = 0; i < n; i++)
            out[i] = 'a';
        out[n] = '\0';
        out[n - a - 1] = out[n - b - 1] = 'b';
        cout << out << '\n';
    }
    return 0;
}

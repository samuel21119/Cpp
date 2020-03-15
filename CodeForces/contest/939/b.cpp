/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep  9 14:55:38 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
long long n, tmp, mod, num;
int k, ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    mod = 1LL << 62;
    for (int i = 0; i < k; i++) {
        cin >> tmp;
        if (n % tmp < mod)
            ans = i + 1, mod = n % tmp, num = tmp;
    }
    cout << ans << ' ' << n / num << '\n';
    return 0;
}

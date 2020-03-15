/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Dec 28 22:38:07 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
string s;
ll count1, count2;
ll ans;
ll mod = 998244353;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[0] == s[i])
            count1++;
        else
            break;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[n - 1] == s[i])
            count2++;
        else
            break;
    }
    //cout << count1 << count2;
    if (s[0] == s[n - 1]) {
        count1++, count2++;
        ans = count1 * count2 % mod;
    }else {
        ans = count1 + count2 + 1;
    }
    cout << ans;
    return 0;
}

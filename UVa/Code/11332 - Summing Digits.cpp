/*************************************************************************
  > File Name: 11332 - Summing Digits.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Jan 26 10:35:24 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll input;
int ans;
void calc(ll i) {
    ans = 0;
    while (i) {
        ans += i % 10;
        i /= 10;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> input && input != 0) {
        calc(input);
        while (ans >= 10)
            calc(ans);
        cout << ans << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Sep 21 22:58:14 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long a, b, ans = 0;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        ans = max(ans, a + b);
    }
    cout << ans << '\n';
    return 0;
}

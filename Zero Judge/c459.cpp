/*************************************************************************
  > File Name: c459.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec  1 22:15:50 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int p(int a, int cnt) {
    if (cnt <= 1)
        return a;
    return a * p(a, cnt - 1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, b, sum1, sum2, len;
    sum1 = sum2 = 0;
    cin >> b >> n;
    len = to_string(n).length();
    for (int mul = 1; n; mul *= b) {
        sum1 += n % 10 * mul;
        sum2 += p(n % 10, len);
        n /= 10;
    }
    cout << (sum1 == sum2 ? "YES" : "NO") << '\n';
    return 0;
}

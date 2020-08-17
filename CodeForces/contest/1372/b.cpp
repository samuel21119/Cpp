/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Jul 11 23:08:41 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool a = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int t = n / i;
                cout << t << ' ' << n - t << '\n';
                a = 1;
                break;
            }
        }
        if (!a)
            cout << 1 << ' ' << n - 1 << '\n';
    }
    return 0;
}

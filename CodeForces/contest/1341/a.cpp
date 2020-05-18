/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Apr 23 22:26:09 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum1 = n * (a - b);
        int sum2 = n * (a + b);
        int t1 = c - d;
        int t2 = c + d;
        if (sum1 > t2 || sum2 < t1)
            cout << "No";
        else
            cout << "Yes";
        cout << '\n';
    }
    return 0;
}

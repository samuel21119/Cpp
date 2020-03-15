/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 22 20:29:22 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int sum1, sum2, n;
int a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum1 += a;
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum2 += a;
    }
    cout << (sum1 >= sum2 ? "Yes" : "No");
    return 0;
}

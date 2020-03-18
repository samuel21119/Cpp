/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 17 19:06:31 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int h, n, sum;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> n;
    while (n--) {
        int a;
        cin >> a;
        sum += a;
    }
    cout << (sum >= h ? "Yes" : "No") << '\n';
    return 0;
}

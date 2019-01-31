/*************************************************************************
  > File Name: 10696 - f91.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Oct  2 16:48:58 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int f91(int i) {
    if (i < 101)
        return f91(f91(i + 11));
    return i - 10;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n)
        cout << "f91(" << n << ") = " << f91(n) << '\n';
    return 0;
}

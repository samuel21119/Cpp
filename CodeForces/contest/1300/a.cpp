/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Feb 11 13:50:33 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t, n;
int in[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int sum, zero;
        sum = zero = 0;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
            sum += in[i];
            zero += in[i] == 0;
        }
        sum += zero;
        if (sum == 0)
            cout << zero + 1 << '\n';
        else
            cout << zero << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 14 20:23:35 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <= 1000; i += 7)
            for (int j = 0; j <= 1000; j += 5) {
                int k = n - i - j;
                if (k >= 0 && k % 3 == 0) {
                    cout << k / 3 << ' ' << j / 5 << ' ' << i / 7 << '\n';
                    goto con;
                }
            }
        cout << "-1\n";
        con:;
    }
    return 0;
}

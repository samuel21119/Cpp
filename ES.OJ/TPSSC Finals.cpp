/*************************************************************************
  > File Name: TPSSC Finals.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Feb  1 14:10:29 2018
*************************************************************************/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long x, m, M;
    int c, n, k;
    cin >> c;
    while (c--) {
        cin >> n >> m >> M >> k;
        x = n;
        for (int i = 0; i < k; i++)
            x = (x * m + 1) % M;
        cout << x % 3 << '\n';
    }
}

/*************************************************************************
  > File Name: 00105 - The Skyline Problem.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed May  2 22:04:26 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, h, r;
    int L, R;
    L = 100000;
    R = -1;
    int H[10010];
    for (int i = 0; i < 10010; i++) H[i] = 0;
    while (cin >> l >> h >> r) {
        for (int i = l; i < r; i++)
            H[i] = max(H[i], h);
        L = min(L, l);
        R = max(R, r);
    }
    int tmp = -1;
    bool space = false;
    for (int i = L; i <= R; i++) {
        if (tmp == H[i])
            continue;
        if (space)
            cout << ' ';
        else
            space = true;
        cout << i << ' ' << H[i];
        tmp = H[i];
    }
    cout << '\n';
    return 0;
}

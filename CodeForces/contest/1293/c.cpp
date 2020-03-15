/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan 20 09:54:28 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool state[2][100010];
int cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    while (q--) {
        int x, y;
        cin >> x >> y; x--, y--;
        int d = state[x][y] ? -1 : 1;
        state[x][y] ^= 1;
        for (int i = y - 1; i <= y + 1; i++) {
            if (i < 0 || i >= n) continue;
            cnt += state[!x][i] == 1 ? d : 0;
        }
        cout << (cnt == 0 ? "Yes" : "No") << '\n';
    }
    return 0;
}

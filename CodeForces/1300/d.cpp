/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Feb 11 14:33:45 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
    int x, y;
    node() {}
    node(int _x, int _y) {
        x = _x, y = _y;
    }
}in[100001];
set<pair<int, int>> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i].x >> in[i].y;
    }
    in[n] = in[0];
    if (n & 1) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n / 2; i++) {
        if (in[i].x - in[i + 1].x != -in[i + n / 2].x + in[i + n / 2 + 1].x || in[i].y - in[i + 1].y != -in[i + n / 2].y + in[i + n / 2 + 1].y) {
            cout << "NO\n";
            cout << i << '\n';
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

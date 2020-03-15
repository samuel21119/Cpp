/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Aug  8 21:59:21 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n[1001];
    int a, b, c, d, tmp;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c >> d;
        n[i] = a + b + c + d;
        if (!i)
            tmp = n[i];
    }
    sort(n, n + e, cmp);
    for (int i = 0; i < e; i++)
        if (n[i] == tmp) {
            cout << i + 1 << '\n';
            return 0;
        }
    return 0;
}

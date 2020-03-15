/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep  9 14:49:03 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int in[5001];
int n;
int check(int i) {
    if (in[in[in[i]]] == i)
        return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    for (int i = 1; i <= n; i++) {
        if (check(i)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

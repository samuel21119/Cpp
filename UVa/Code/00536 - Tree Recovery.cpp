/*************************************************************************
  > File Name: 00536 - Tree Recovery.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Aug 29 12:11:02 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int solve(string &pre, string &in, int pi, int low, int high) {
    if (low >= high)
        return pi;
    for (int i = low; i < high; i++) {
        if (in[i] != pre[pi])
            continue;
        pi = solve(pre, in, pi + 1, low, i);
        pi = solve(pre, in, pi, i + 1, high);
        cout << in[i];
        break;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string pre, in;
    while (cin >> pre >> in) {
        solve(pre, in, 0, 0, pre.size());
        cout << '\n';
    }
    return 0;
}

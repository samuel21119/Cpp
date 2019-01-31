/*************************************************************************
  > File Name: 11192 - Group Reverse.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Apr  3 19:50:57 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, len;
    char in[105];
    while (cin >> n && n) {
        cin >> in;
        len = strlen(in);
        n = len / n;
        len /= n;
        for (int i = 0; i < len; i++)
            reverse(in + i * n, in + i * n + n);
        cout << in << '\n';
    }
    return 0;
}

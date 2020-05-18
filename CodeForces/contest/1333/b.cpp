/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Apr  8 22:52:24 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in1[100000];
int in2[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in1[i];
        for (int i = 0; i < n; i++)
            cin >> in2[i];
        bool a, b, ans;
        a = b = 0;
        ans = 1;
        for (int i = 0; i < n; i++) {
            if (in1[i] != in2[i]) {
                if (in1[i] > in2[i])
                    ans &= b;
                else
                    ans &= a;
            }
            a |= in1[i] == 1;
            b |= in1[i] == -1;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}

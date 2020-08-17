/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Aug 12 22:07:49 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int t;
int in[4];
bool check() {
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        cnt += in[i] % 2;
    return cnt <= 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 4; i++)
            cin >> in[i];
        int mn = 1e9;
        bool ans = check();
        for (int i = 0; i < 3; i++)
            mn = min(mn, in[i]);
        if (mn > 0) {
            for (int i = 0; i < 3; i++)
                in[i]--;
            in[3] += 3;
            ans |= check();
        }
        cout << (ans ? "Yes" : "No") << '\n';
    }
    return 0;
}

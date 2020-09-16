/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Sep 14 15:44:11 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt0, cnt1;
        cnt0 = cnt1 = 0;
        while (n--) {
            int a;
            cin >> a;
            if (a)
                cnt1++;
            else
                cnt0++;
        }
        if (cnt1 > cnt0) {
            if (cnt1 & 1)
                cnt1--;
            cout << cnt1 << '\n';
            while (cnt1--)
                cout << "1 ";
        }else {
            cout << cnt0 << '\n';
            while (cnt0--)
                cout << "0 ";
        }
        cout << '\n';
    }
    return 0;
}

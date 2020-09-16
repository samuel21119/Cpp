/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Sep 14 16:16:37 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    if (b)
        return gcd(b, a % b);
    return a;
}

int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        multiset<int> s;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s.insert(a);
        }
        int mx = *s.rbegin();
        cout << mx << ' ';
        s.erase(s.find(mx));
        for (int i = 1; i < n; i++) {
            int mx2 = 0, pt = -1;
            for (int i : s) {
                int t = gcd(mx, i);
                if (t > mx2) {
                    mx2 = t;
                    pt = i;
                }
            }
            cout << pt << ' ';
            s.erase(s.find(pt));
            mx = mx2;
        }
        cout << '\n';
    }
    return 0;
}

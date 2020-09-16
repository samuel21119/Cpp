/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Sep 15 10:05:30 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int ind;
int ans[10010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ind = 1;
    for (int i = 2; i <= n; i++) {
        int ans1, ans2;
        cout << "? " << ind << ' ' << i << endl;
        cin >> ans1;
        cout << "? " << i << ' ' << ind << endl;
        cin >> ans2;
        if (ans1 > ans2) {
            ans[ind] = ans1;
            ind = i;
        }else {
            ans[i] = ans2;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << (ans[i] ? ans[i] : n) << ' ';
    }
    cout << endl;
    return 0;
}

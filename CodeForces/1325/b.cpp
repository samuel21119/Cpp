/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar 14 22:38:22 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        cout << v.size() << '\n';
    }
    return 0;
}

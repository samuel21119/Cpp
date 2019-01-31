/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 22 21:16:48 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, q;
bool x[200001], y[200001];
set<int> s1, s2;
int a, b;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        s1.insert(a);
        s2.insert(b);
    }
    cout << max(n - s1.size(), m - s2.size());
    return 0;
}

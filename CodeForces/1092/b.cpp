/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Dec 18 22:09:42 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, ans;
int in[110];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n ;i++)
        cin >> in[i];
    sort(in, in + n);
    n >>= 1;
    for (int i = 0; i < n; i++) {
        int a = i * 2;
        int b = a + 1;
        ans += in[b] - in[a];
    }
    cout << ans << '\n';
    return 0;
}

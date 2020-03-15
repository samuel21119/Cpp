/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 22 20:29:27 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, x, a[100005], b[100005], ans=3;
bool use[100005], vis2[100005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(use[a[i]])
            ans = 0;
        use[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = x & a[i];
        if (b[i] != a[i]) {
            if(use[b[i]])
                ans = min(ans, 1);
            if(vis2[b[i]])
                ans = min(ans, 2);
            vis2[b[i]] = 1;
        }
    }
    cout << (ans == 3 ? -1 : ans) << '\n';
    return 0;
}

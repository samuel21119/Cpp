/*************************************************************************
  > File Name: 1993.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 24 18:58:10 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bitset<100001> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h, t;
    int a, b, c;
    cin >> t;
    while(t--) {
        ans.reset();
        ans[0] = 1;
        cin >> n >> h;
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            ans = (ans << a) | (ans << b) | (ans << c);
        }
        a = 0;
        for (int i = 1; i <= h; i++)
            if (ans[i])
                a = i;
        if (!a)
            cout << "no solution\n";
        else
            cout << a << '\n';
    }
    return 0;
}

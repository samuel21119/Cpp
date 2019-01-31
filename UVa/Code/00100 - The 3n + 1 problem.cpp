/*************************************************************************
  > File Name: 100 - The 3n + 1 problem.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:00:06 2017
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[1000001], a, b, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ans[1] = 1;
    ans[2] = 2;
    for (ll i = 3; i <= 1000000; i++) {
        ll j = i;
        cnt = 0;
        while (j != 1) {
            if (j % 2)
                j = 3 * j + 1, cnt++;
            j /= 2;
            cnt++;
            if (j < i)
                cnt += ans[j], j = 1;
        }
        ans[i] = cnt;
    }
    while (cin >> a >> b) {
        cout << a << ' ' << b << ' ';
        if (a > b)
            swap(a, b);
        int mx = ans[a];
        for (int i = a + 1; i <= b; i++)
            mx = max(mx, ans[i]);
        cout << mx << '\n';
    }
}

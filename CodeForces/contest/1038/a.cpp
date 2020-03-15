/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep  6 22:33:01 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int cnt[27];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    char a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cnt[a - 'A']++;
    }
    ans = 1000000000;
    for (int i = 0; i < k; i++)
        ans = min(ans, cnt[i]);
    cout << ans * k << '\n';;
    return 0;
}

/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Aug 11 21:58:43 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int a[1001], n;
bool visit[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        memset(visit, 0, sizeof(visit));
        visit[i] = 1;
        int n = a[i];
        while (!visit[n]) {
            visit[n] = 1;
            n = a[n];
        }
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}

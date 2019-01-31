/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Oct 29 22:09:19 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int in[10][100010];
int pos[10][100010];
int n, m;
long long ans;
inline long long calc(long long i) {
    return i * (i + 1) >> 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> in[i][j];
            pos[i][in[i][j]] = j;
        }
    int prev = 0;
    int now = 0;
    for (int i = 1; i < n; i++) {
        int num1 = in[0][i - 1];
        int num2 = in[0][i];
        bool add = 1;
        for (int j = 1; j < m && add; j++)
            add &= pos[j][num1] + 1 == pos[j][num2];
        if (add)
            now++;
        else {
            ans += calc(now - prev);
            prev = now;
        }
    }
    ans += calc(now - prev);
    cout << ans + n << '\n';
    return 0;
}

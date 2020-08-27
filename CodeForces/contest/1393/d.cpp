/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Aug 27 14:51:00 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
char in[2010][2010];
int dpU[2010][2010];
int dpD[2010][2010];
int cntL[2010], cntR[2010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> in[i][j];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            dpU[i][j] = 0;
            if (i != 1 && in[i][j] == in[i - 1][j])
                dpU[i][j] = dpU[i - 1][j] + 1;
        }
    for (int i = n; i > 0; i--)
        for (int j = 1; j <= m; j++) {
            dpD[i][j] = 0;
            if (i != n && in[i][j] == in[i + 1][j])
                dpD[i][j] = dpD[i + 1][j] + 1;
        }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;) {
            int end = j;
            while (end <= m && in[i][j] == in[i][end]) end++;
            int mx = j;
            for (int x = j; x < end; x++) {
                mx = max(mx, x - min(dpU[i][x], dpD[i][x]));
                cntL[x] = x - mx + 1;
            }
            j = end;
        }

        for (int j = m; j > 0;) {
            int end = j;
            while (end > 0 && in[i][j] == in[i][end]) end--;
            int mn = j;
            for (int x = j; x > end; x--) {
                mn = min(mn, x + min(dpU[i][x], dpD[i][x]));
                cntR[x] = mn - x + 1;
            }
            j = end;
        }
        for (int j = 1; j <= m; j++)
            ans += min(cntL[j], cntR[j]);
    }
    cout << ans << '\n';
    return 0;
}

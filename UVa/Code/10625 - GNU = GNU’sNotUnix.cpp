/*************************************************************************
  > File Name: 10625 - GNU = GNU’sNotUnix.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Dec 17 12:33:06 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull change[128][128];
ull sum[2][128];
char c, s[110], t1, t2;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, q;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(change, 0, sizeof(change));
        while (n--) {
            cin >> c >> t1 >> t2 >> s;
            for (int i = 0; s[i] != '\0'; i++)
                change[c][s[i]]++;
            change[c][c]--;
        }
        cin >> q;
        while (q--) {
            cin >> s >> c >> n;
            memset(sum[n & 1], 0, sizeof(sum[0]));
            for (int i = 0; s[i] != '\0'; i++)
                sum[n & 1][s[i]]++;
            while (n--) {
                memcpy(sum[n & 1], sum[!(n & 1)], sizeof(sum[0]));
                for (int i = 33; i <= 126; i++)
                    for (int j = 33; j <= 126; j++)
                        sum[n & 1][i] += sum[!(n & 1)][j] * change[j][i];
            }
            cout << sum[0][c] << '\n';
        }
    }
    return 0;
}

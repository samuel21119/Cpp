/*************************************************************************
  > File Name: 11456 - Trainsorting.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat May 19 14:10:47 2018
*************************************************************************/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
int up[2002], down[2002];
int input[2003];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n;
    cin >> c;
    while(c--) {
        cin >> n;
        for (int i = n; i; i--)
            cin >> input[i];
        int ans = 0;
        for (int i = 1; i <= n; i++) up[i] = down[i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (input[j] < input[i])
                    up[i] = max(up[i], up[j] + 1);
                else
                    down[i] = max(down[i], down[j] + 1);
            }
            ans = max(ans, up[i] + down[i] - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}

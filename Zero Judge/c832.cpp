/*************************************************************************
  > File Name: c832.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri 09 Nov 2018 07:21:23 AM PST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bool use[110];
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        memset(use, 0, sizeof(use));
        cnt = 0;
        int i = 6, a;
        while (i--) {
            cin >> a;
            if (!use[a])
                cnt++;
            use[a] = 1;
        }
        cout << (cnt > 2 ? "Yes\n" : "No\n");
    }
    return 0;
}

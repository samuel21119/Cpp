/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Apr 10 22:35:14 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
pair<int, int> in[110];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            in[i] = {a, b};
        }
        bool ans = 1;
        int lev, clr;
        lev = clr = -1;
        for (int i = 0; i < n; i++) {
            int nowL = in[i].first;
            int nowC = in[i].second;
            if (nowL > lev) {
                if (nowC < clr)
                    ans = 0;
                if (nowL - lev < nowC - clr)
                    ans = 0;
                lev = nowL;
                clr = nowC;
            }else if (nowL == lev) {
                ans &= clr == nowC;
            }else {
                ans = 0;
            }
            if (!ans)
                break;
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}

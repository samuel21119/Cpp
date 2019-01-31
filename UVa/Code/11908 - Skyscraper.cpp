/*************************************************************************
  > File Name: 11908 - Skyscraper.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jun  3 16:54:48 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
struct str {
    int down, up;
    int cost;
    bool operator < (str const &b) const {
        if (up < b.up)
            return true;
        return false;
    }
    str (int d, int u, int c) : down(d), up(u), cost(c){}
    str (){}
}input[30001];
int dp[30001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, t1, t2, t3;
    cin >> c;
    for (int i = 0; i < c;) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t1 >> t2 >> t3;
            input[i] = {t1, t1 + t2 - 1, t3};
        }
        sort(input, input + n);
        memset(dp, 0, sizeof(dp));
        dp[0] = input[0].cost;
        for (int i = 1; i < n; i++) {
            int l = 0, r = i;
            int m;
            int down = input[i].down;
            while (l < r - 1) {
                m = (l + r) >> 1;
                if (input[m].up >= down)
                    r = m;
                if (input[m].up < down)
                    l = m;
            }
            if (input[l].up >= down)
                dp[i] = max(dp[i - 1], input[i].cost);
            else
                dp[i] = max(dp[i - 1], dp[l] + input[i].cost);
        }
        cout << "Case " << ++i << ": " << dp[n - 1] << '\n';
    }
    return 0;
}

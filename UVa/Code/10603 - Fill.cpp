/*************************************************************************
  > File Name: 10603 - Fill.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jan 27 13:29:27 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int A, B, C, t, sum, mx = 2139062143;
int a, b, c, pour;
int target;
int dp[201][201], ans[201];
struct abc {
    int a, b;
    int p;
    abc() {}
    abc(int a, int b, int p) : a(a), b(b), p(p) {}
}tmp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> A >> B >> C >> target;
        sum = C;
        memset(dp, 127, sizeof(dp));
        memset(ans, 127, sizeof(ans));
        queue<abc> q;
        q.push({0, 0, 0});
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            a = tmp.a;
            b = tmp.b;
            c = sum - a - b;
            pour = tmp.p;
            if (ans[target] <= pour)
                continue;
            if (dp[a][b] <= pour)
                continue;
            dp[a][b] = pour;
            ans[a] = min(ans[a], pour);
            ans[b] = min(ans[b], pour);
            ans[c] = min(ans[c], pour);
            if (a > 0 && b < B) {
                if (a < B - b)
                    q.push({0, a + b, pour + a});
                else
                    q.push({a - (B - b), B, pour + (B - b)});
            }
            if (a > 0 && c < C) {
                if (a < C - c)
                    q.push({0, b, pour + a});
                else
                    q.push({a - (C - c), b, pour + (C - c)});
            }
            if (b > 0 && a < A) {
                if (b < A - a)
                    q.push({a + b, 0, pour + b});
                else
                    q.push({A, b - (A - a), pour + (A - a)});
            }
            if (b > 0 && c < C) {
                if (b < C - c)
                    q.push({a, 0, pour + b});
                else
                    q.push({a, b - (C - c), pour + (C - c)});
            }
            if (c > 0 && a < A) {
                if (c < A - a)
                    q.push({a + c, b, pour + c});
                else
                    q.push({A, b, pour + (A - a)});
            }
            if (c > 0 && b < B) {
                if (c < B - b)
                    q.push({a, b + c, pour + c});
                else
                    q.push({a, B, pour + (B - b)});
            }
        }
        if (ans[target] == mx)
            while (ans[target] == mx) target--;
        cout << ans[target] << ' ' << target << '\n';
    }
    return 0;
}

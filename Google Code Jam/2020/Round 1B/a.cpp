/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Apr 19 23:58:56 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int X, Y;
int xx, yy;
char ans[40];
bool dfs(int x, int y, int ind) {
    if (ind > 38)
        return 0;
    if (x % 2 == y % 2 && x + y > 0)
        return 0;
    if (x + y == 0)
        return 1;
    //cout  << x % 2 << ' ' << y % 2 << ' ' << ind << endl;
    if (x % 2 == 1) {
        if (dfs((x - 1) >> 1, y >> 1, ind + 1))
            ans[ind] = X < 0 ? 'W' : 'E';
        else if (dfs((x + 1) >> 1, y >> 1, ind + 1))
            ans[ind] = X < 0 ? 'E' : 'W';
        else
            return 0;
    }else {
        if (dfs(x >> 1, (y - 1) >> 1, ind + 1))
            ans[ind] = Y < 0 ? 'S' : 'N';
        else if (dfs(x >> 1, (y + 1) >> 1, ind + 1))
            ans[ind] = Y < 0 ? 'N' : 'S';
        else
            return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> X >> Y;
        cout << "Case #" << t << ": ";
        memset(ans, 0, sizeof(ans));
        if (dfs(abs(X), abs(Y), 0))
            cout << ans;
        else
            cout << "IMPOSSIBLE";
        cout << '\n';
    }
    return 0;
}

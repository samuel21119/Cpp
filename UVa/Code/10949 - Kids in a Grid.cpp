/*************************************************************************
  > File Name: 10949 - Kids in a Grid.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Aug  9 19:33:40 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string road[20];
void input(string &t) {
    int len, x, y;
    char c;
    cin >> len >> x >> y;
    x--; y--;
    t += road[x][y];
    while (len--) {
        cin >> c;
        switch (c) {
            case 'N':
                x--;
                break;
            case 'S':
                x++;
                break;
            case 'W':
                y--;
                break;
            case 'E':
                y++;
        }
        t += road[x][y];
    }
}
int sol(string a, string b) { //a > b
    vector<int> tmp[128];
    for (int i = 0; i < a.length(); i++)
        tmp[a[i]].push_back(i);
    vector<int> lis;
    lis.push_back(-1);
    for (int i = 0; i < b.length(); i++) {
        int now = b[i];
        for (int i = tmp[now].size() - 1; i >= 0; i--) {
            if (tmp[now][i] > lis.back())
                lis.push_back(tmp[now][i]);
            else
                *lower_bound(lis.begin(), lis.end(), tmp[now][i]) = tmp[now][i];
        }
    }
    return lis.size() - 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    for (int i = 0; i < c;) {
        string a, b;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> road[i];
        input(a);
        input(b);
        int ans = (a.length() > b.length() ? sol(a, b) : sol(b, a));
        cout << "Case " << ++i << ": " << a.length() - ans << ' ' << b.length() - ans << '\n';
    }
    return 0;
}

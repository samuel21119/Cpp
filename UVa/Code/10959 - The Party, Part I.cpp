/*************************************************************************
  > File Name: 10959 - The Party, Part I.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Jul 10 12:02:46 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int p, d;
int num[1000];
bool dance[1000][1000];
const int MAX = 1 << 30;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, a, b;
    cin >> c;
    while (c--) {
        cin >> p >> d;
        num[0] = 0;
        for (int i = 1; i < p; i++)
            num[i] = MAX;
        num[0] = 0;
        memset(dance, 0, sizeof(dance));
        while (d--) {
            cin >> a >> b;
            dance[a][b] = dance[b][a] = 1;
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 1; i < p; i++)
                if (dance[cur][i] && num[i] == MAX) {
                    q.push(i);
                    num[i] = num[cur] + 1;
                }
        }
        for (int i = 1; i < p; i++)
            cout << num[i] << '\n';
        if (c)
            cout << '\n';
    }
    return 0;
}

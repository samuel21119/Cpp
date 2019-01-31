/*************************************************************************
  > File Name: c833.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri 09 Nov 2018 07:24:05 AM PST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
bool row[3010];
bool col[3010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            if (a == '#')
                row[i] = col[j] = 1;
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (row[i] || col[j])
                cout << '#';
            else
                cout << 'X';
        cout << '\n';
    }
    return 0;
}

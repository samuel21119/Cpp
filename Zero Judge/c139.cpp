/*************************************************************************
  > File Name: c139.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar 28 20:53:25 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bool r[5][5];
int run[9];

void dfs(int index) {
    int pos = run[index - 1];
    if (index == 9) {
        for (int i = 0; i < 9; i++)
            cout << run[i] + 1;
        cout << '\n';
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (!(r[pos][i] && r[i][pos]))
            continue;
        r[pos][i] = 0;
        run[index] = i;
        dfs(index + 1);
        r[pos][i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    r[0][1] = r[1][0] = r[1][2] = r[2][1] = r[2][4] = r[4][2] = r[4][0] = r[0][4] = r[0][2] = r[2][0] = r[1][4] = r[4][1] = r[4][3] = r[3][4] = r[2][3] = r[3][2] = 1;
    run[0] = 0;
    dfs(1);
}

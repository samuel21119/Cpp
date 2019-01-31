/*************************************************************************
  > File Name: 572 - Oil Deposits.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:34:28 2017
*************************************************************************/

#include <iostream>
using namespace std;
char d[100][100];
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int l, c;
void dfs(int y, int x) {
    int tempx, tempy;
    for (int i = 0; i < 8; i++) {
        tempx = dx[i] + x;
        tempy = dy[i] + y;
        if (tempy >= 0 && tempy < l && tempx >= 0 && tempx < c) {
            if (d[tempy][tempx] == '@') {
                d[tempy][tempx] = '*';
                dfs(tempy, tempx);
            }
        }
    }
}
int main() {
    int count;
    while (1) {
        count = 0;
        cin >> l >> c;
        if (l == c && !c)
            break;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                cin >> d[i][j];
            }
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                if (d[i][j] == '@') {
                    count++;
                    d[i][j] = '*';
                    dfs(i, j);
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}

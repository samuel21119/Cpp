/*************************************************************************
  > File Name: 10189 - Minesweeper.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:55:47 2017
*************************************************************************/

#include <iostream>
using namespace std;
int r[102][102];
int X[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int Y[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, c, count = 1;
    char in;
    while (1) {
        cin >> l >> c;
        if (l == c && !l)
            break;
        for (int i = 1; i <= l; i++)
            for (int j = 1; j <= c; j++)
                r[i][j] = 0;
        if (count > 1)
            cout << '\n';
        cout << "Field #" << count++ << ":\n";
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> in;
                if (in == '*') {
                    for (int k = 0; k < 8; k++)
                        r[i + Y[k]][j + X[k]] += 1;
                    r[i][j] = -100;
                }
            }
        }
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= c; j++) {
                if (r[i][j] < 0)
                    cout << '*';
                else 
                    cout << r[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}


/*************************************************************************
  > File Name: 167 - The Sultans Successors.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:01:38 2017
*************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#define endl '\n'
using namespace std;
int in[8][8];
int _max;
int lineuse[8];
void dfs(int c, int sum) {
    for (int i = 0; i < 8; i++) {
        if (lineuse[i] >= 0)
            continue;
        for (int j = 1; j <= c; j++) {
              if (i + j < 8)
                  if (lineuse[i + j] == c - j)
                      goto _continue;
              if (i - j >= 0)
                  if (lineuse[i - j] == c - j)
                      goto _continue;
        }
        if (c < 7) {
            lineuse[i] = c;
            dfs(c + 1, sum + in[c][i]);
            lineuse[i] = -1;
        }else {
            _max = max(_max, sum + in[c][i]);
            return;
        }
        _continue:;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count;
    cin >> count;
    while(count--) {
        _max = 0;
        for (int i = 0; i <8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> in[i][j];
            }
        }
        for (int i = 0; i < 8; i++) {
            lineuse[i] = -1;
        }
        dfs(0, 0);
        printf("%5d\n", _max);
    }
    return 0;
}


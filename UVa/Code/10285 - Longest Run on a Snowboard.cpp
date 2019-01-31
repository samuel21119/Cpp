/*************************************************************************
  > File Name: 10285 - Longest Run on a Snowboard.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:56:06 2017
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int N, R, C, MAX;
int input[100][100];
int distant[100][100];
char name[1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dfs(int x, int y) {
    int temp_x, temp_y;
    for (int i = 0; i < 4; i++) {
        temp_x = x + dx[i];
        temp_y = y + dy[i];
        if (temp_x >= 0 && temp_x < C && temp_y >= 0 && temp_y < R) {
            if (input[temp_x][temp_y] < input[x][y]) {
                if (distant[temp_x][temp_y] == 0)
                    distant[temp_x][temp_y] = dfs(temp_x, temp_y);
                distant[x][y] = max(distant[temp_x][temp_y] + 1, distant[x][y]);
            }
        }
    }
    return distant[x][y];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--) {
        MAX = 1;
        cin >> name >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> input[j][i];
                distant[j][i] = 0;
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                MAX = max(dfs(j, i) + 1, MAX);
            }
        }
        cout << name << ": " << MAX << endl;
    }
    return 0;
}
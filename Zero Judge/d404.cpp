#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;
int N, R, C, MAX;
int input[100][100];
int distant[100][100];
char name[1000];
int dfs(int x, int y, int count) {
    int temp_x, temp_y, temp_count;
    temp_count = count;
    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0:
                temp_x = x + 1;
                temp_y = y;
                break;
            case 1:
                temp_x = x - 1;
                temp_y = y;
                break;
            case 2:
                temp_x = x;
                temp_y = y + 1;
                break;
            case 3:
                temp_x = x;
                temp_y = y - 1;
                break;
        }
        if (temp_x >= 0 && temp_x < C && temp_y >= 0 && temp_y < R) {
            if (input[temp_x][temp_y] < input[x][y]) {
                if (distant[temp_x][temp_y] == 0) {
                    distant[temp_x][temp_y] = dfs(temp_x, temp_y, 1);
                }
                temp_count = max(distant[temp_x][temp_y] + count, temp_count);
            }
        }
    }
    return temp_count;
}
int main() {
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
                MAX = max(dfs(j, i, 1), MAX);
            }
        }
        cout << name << ": " << MAX << endl;
    }
}

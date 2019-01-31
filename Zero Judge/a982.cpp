#include <iostream>
#include <queue>
#define INF 2147483647
using namespace std;
struct XY {
    int X, Y;
};
int N;
char input[100][100];
int distant[100][100];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
            distant[i][j] = INF;
        }
    }
    //bfs:
        queue<XY> que;
        XY Start, temp;
        int x, y, temp_x, temp_y;
        Start.X = 1;
        Start.Y = 1;
        distant[1][1] = 1;
        que.push(Start);
        while (que.size()) {
            temp = que.front();
            que.pop();
            x = temp.X;
            y = temp.Y;
            if (x == N - 2 && y == N - 2) {
                break;
            }
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
                if (temp_x >= 0 && temp_y >= 0 && temp_x < N && temp_y < N && distant[temp_x][temp_y] == INF) {
                    if (input[temp_y][temp_x] == '.') {
                        temp.X = temp_x;
                        temp.Y = temp_y;
                        que.push(temp);
                        distant[temp_x][temp_y] = distant[x][y] + 1;
                    }
                }
            }
        }
    if (distant[N - 2][N - 2] > 0 && distant[N - 2][N - 2] != INF) {
        cout << distant[N - 2][N - 2];
    }else {
        cout << "No solution!";
    }
}

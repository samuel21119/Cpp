#include <iostream>
#include <queue>
using namespace std;
int input[100][100];
int output[100][100];
int S, Start;
int X, Y;
struct addr {
    int x;
    int y;
};
void bfs() {
    queue<addr> que;
    addr temp, temp2;
    temp.x = Start;
    temp.y = 0;
    que.push(temp);
    while (que.size()) {
        temp = que.front();
        que.pop();
        if (S == 1) {
            for (int i = 0; i < 4; i++) {
                temp2.x = temp.x;
                temp2.y = temp.y;
                switch (i) {
                    case 0:
                        temp2.x += 1;
                        break;
                    case 1:
                        temp2.x -= 1;
                        break;
                    case 2:
                        temp2.y += 1;
                        break;
                    case 3:
                        temp2.y -= 1;
                        break;
                }
                if (temp2.x >= 0 && temp2.x < X && temp2.y >= 0 && temp2.y < Y) {
                    if (input[temp2.x][temp2.y] == 1 && output[temp2.x][temp2.y] == 0) {
                        que.push(temp2);
                        output[temp2.x][temp2.y] = output[temp.x][temp.y] + 1;
                    }
                }
            }
        }else {
            for (int i = 0; i < 3; i++) {
                temp2.x = temp.x;
                temp2.y = temp.y;
                switch (i) {
                    case 0:
                        temp2.x += 1;
                        break;
                    case 1:
                        temp2.x -= 1;
                        break;
                    case 2:
                        temp2.y += 1;
                }
                if (temp2.x >= 0 && temp.x < X && temp2.y >= 0 && temp2.y < Y) {
                    if (input[temp2.x][temp2.y] == 1 && output[temp2.x][temp2.y] == 0) {
                        que.push(temp2);
                        output[temp2.x][temp2.y] = output[temp.x][temp.y] + 1;
                    }
                }
            }
        }
    }
}
int main() {
    int count = 0;
    while (cin >> S) {
        cin >> Y >> X;
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                cin >> input[x][y];
                output[x][y] = 0;
            }
        }
        for (int x = 0; x < X; x++) {
            if (input[x][0] == 1) {
                Start = x;
                output[x][0] = 1;
                x = X;
            }
        }
        bfs();
        cout << "Case " << ++count << ":\n";
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++){
                cout << output[x][y];
                if (x != X - 1) {
                    cout << ' ';
                }else {
                    cout << '\n';
                }
            }
        }
    }
}

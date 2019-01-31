#include <iostream>
#include <cmath>
#include <utility>
#include <queue>
#define INF 2147483647
using namespace std;
int L, R, C;
struct addr{
    int L, R, C;
};
addr S;
char input[30][30][30];
int distant[30][30][30];
int bfs () {
    queue<addr> que;
    for (int l = 0; l < L; l++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                distant[r][c][l] = INF;
            }
        }
    }
    distant[S.R][S.C][S.L] = 0;
    que.push(S);
    addr pop = que.front();
    int temp_R, temp_C, temp_L;
    while (que.size()) {
        pop = que.front();
        que.pop();
        if (input[pop.R][pop.C][pop.L] == 'E')
            break;
        for (int direction = 0; direction < 6; direction++) {
            switch (direction) {
                case 0:
                    temp_L = pop.L;
                    temp_R = pop.R + 1;
                    temp_C = pop.C;
                    break;
                case 1:
                    temp_L = pop.L;
                    temp_R = pop.R - 1;
                    temp_C = pop.C;
                    break;
                case 2:
                    temp_L = pop.L;
                    temp_R = pop.R;
                    temp_C = pop.C + 1;
                    break;
                case 3:
                    temp_L = pop.L;
                    temp_R = pop.R;
                    temp_C = pop.C - 1;
                    break;
                case 4:
                    temp_L = pop.L + 1;
                    temp_R = pop.R;
                    temp_C = pop.C;
                    break;
                case 5:
                    temp_L = pop.L - 1;
                    temp_R = pop.R;
                    temp_C = pop.C;
                    break;
            }
            if (temp_L < L && temp_C < C && temp_R >= 0 && temp_L >= 0 && temp_C >= 0 && distant[temp_R][temp_C][temp_L] == INF) {
                if (input[temp_R][temp_C][temp_L] == '.' || input[temp_R][temp_C][temp_L] == 'E') {
                    addr temp_addr;
                    temp_addr.R = temp_R;
                    temp_addr.C = temp_C;
                    temp_addr.L = temp_L;
                    que.push(temp_addr);
                    distant[temp_R][temp_C][temp_L] = distant[pop.R][pop.C][pop.L] + 1;
                }
            }
        }
    }
    return distant[pop.R][pop.C][pop.L];
}
int main() {
    int temp;
    while (cin >> L >> R >> C) {
        if (L == R && R == C && C == 0)
            break;
        for (int l = 0; l < L; l++) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cin >> input[i][j][l];
                }
            }
        }
        for (int l = 0; l < L; l++) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (input[i][j][l] == 'S') {
                        S.L = l;
                        S.R = i;
                        S.C = j;
                        l = L;
                        i = R;
                        j = C;
                    }
                }
            }
        }
        temp = bfs();
        if (temp != 0) {
            cout << "Escaped in " << temp << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
    }
}

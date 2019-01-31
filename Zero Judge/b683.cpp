#include <iostream>
using namespace std;
int count1, count0;
unsigned long long int mul = 1;
char input[31][31];
int H, W;
int target[2];
void search(int x, int y,int local_count1) {
    input[x][y] = '#';
    if (local_count1 >= 7) {
        if ((x + 1 == target[0] && y == target[1]) || (x - 1 == target[0] && y == target[1]) ||
            (x == target[0] && y + 1 == target[1]) || (x == target[0] && y - 1 == target[1])) {
            mul *= ++local_count1;
            count1 += local_count1;
            count0 += 1;
            return;
        }
    }
    if (x - 1 >= 0) {
        if (input[x - 1][y] == '.') {
            search(x - 1, y, local_count1 + 1);
            return;
        }
    }
    if (x + 1 < W) {
        if (input[x + 1][y] == '.') {
            search(x + 1, y, local_count1 + 1);
            return;
        }
    }
    if (y - 1 >= 0) {
        if (input[x][y - 1] == '.') {
            search(x, y - 1, local_count1 + 1);
            return;
        }
    }
    if (y + 1 < H) {
        if (input[x][y + 1] == '.') {
            search(x, y + 1, local_count1 + 1);
            return;
        }
    }
    return;
}
int main() {
    int temp1;
    count1 = count0 = 0;
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            input[i][j] = 'a';
        }
    }
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> input[j][i];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (input[j][i] == '.') {
                target[0] = j; //x
                target[1] = i; //y
                search(j, i, 0);
            }
        }
    }
    if (mul == 1)
        mul = 0;
    cout << count0 << " " << count1 << " " << mul;
}

#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    int x, y, temp;
    cin >> x >> y;
    char input[x * 2 - 1][y];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x * 2 - 1; j++) {
            cin >> input[j][i];
        }
    }
    for (int i = 0; i < x; i++) {
        temp = i * 2;
        for (int j = 0; j < y; j++) {
            if (temp > 0) {
                if (input[temp - 1][j] == '-') {
                    temp -= 2;
                    continue;
                }
            }
            if (temp < x * 2) {
                if (input[temp + 1][j] == '-') {
                    temp += 2;
                    continue;
                }
            }
        }
        cout << temp / 2 + 1;
        if (i < x - 1) {
            cout << " ";
        }
    }
}

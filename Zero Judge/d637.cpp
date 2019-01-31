#include <iostream>
#include <utility>
#include <cmath>
using namespace std;
#define Max 100
int main() {
    int food;
    cin >> food;
    pair<int, int> foods[food];
    for (int i = 0; i < food; i++) {
        cin >> foods[i].first >> foods[i].second;
    }//first : V second : full
    int DP[food + 1][Max + 1];
    for (int j = 0; j <= Max; j++) {
        DP[food][j] = 0;
    }
    for (int i = food - 1; i >= 0; i--) {
        for (int j = 0; j <= Max; j++) {
            if (foods[i].first > j) {
                DP[i][j] = DP[i + 1][j];
            }else {
                DP[i][j] = max(foods[i].second + DP[i + 1][j - foods[i].first], DP[i + 1][j]);
            }
        }
    }
    cout << DP[0][Max];
}

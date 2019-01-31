#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
struct food3 {
    int V, W;
};
int a[700000];
pair<int, int> food_t0[10000];
food3 food_t1[75000];
int power_two[30];
int Max;
int main() {
    int food, inf, total_length;
    inf = total_length = 0;
    cin >> food >> Max;
    power_two[0] = 1;
    for (int i = 1; i < 30; i++) {
        power_two[i] = power_two[i - 1] * 2;
    }
    int V, W, T;
    for (int i = 0, j = 0; i < food; i++) {
        cin >> V >> W >> T;
        if (T == -1) {
            food_t0[inf].first = W;
            food_t0[inf].second = V;
            inf++;
        }
        else {
            int temp = 0, T2;
            T2 = T;
            while (power_two[temp] <= T) {
                temp++;
            }
            food3 food_temp;
            for (int j = 0; j < temp; j++) {
                if (j < temp - 1) {
                    food_temp.V = V * power_two[j];
                    food_temp.W = W * power_two[j];
                    T2 -= power_two[j];
                }
                else {
                    food_temp.V = V * T2;
                    food_temp.W = W * T2;
                }
                food_t1[total_length + j] = food_temp;

            }
            total_length += temp;
        }
    }
    int DP_T1[Max + 1];
    for (int i = 0; i <= Max;) {
        DP_T1[i++] = 0;
    }
    for (int i = 0; i < total_length; i++) {
        for (int j = Max; j >= food_t1[i].W; j--) {
            DP_T1[j] = max(DP_T1[j], DP_T1[j - food_t1[i].W] + food_t1[i].V);
        }
    }
    int DP_T0[Max + 1];
    for (int i = 0; i <= Max;) {
        DP_T0[i++] = 0;
    }
    for (int i = 0; i < inf; i++) {
        for (int j = food_t0[i].first; j <= Max; j++) {
            DP_T0[j] = max(DP_T0[j], DP_T0[j - food_t0[i].first] + food_t0[i].second);
        }
    }
    int max_number = 0;
    for (int i = Max; i >= 0; i--) {
        max_number = max(max_number, DP_T0[i] +  DP_T1[Max - i]);
    }
    cout << max_number;
}

/*************************************************************************
  > File Name: 11951 - Area.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Feb  1 20:32:47 2018
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;

ull input[102][102];
int N, M, K, MaxArea, Cost;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    memset(input, 0, sizeof(input));
    for (int C = 1; C <= c; C++) {
        cin >> N >> M >> K;
        MaxArea = Cost = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) {
                cin >> input[i][j];
                input[i][j] += input[i - 1][j];
                input[i][j] += input[i][j - 1];
                input[i][j] -= input[i - 1][j - 1];
            }
        for (int j1 = 1; j1 <= M; j1++) {
            for (int j2 = j1; j2 > 0; j2--) {
                int P, sum, area;
                P = 1;
                sum = 0;
                for (int i = 1; i <= N; i++) {
                    sum = input[i][j1] - input[i][j2 - 1] - input[P - 1][j1] + input[P - 1][j2 - 1];
                    while (sum > K)
                        sum -= input[P][j1] - input[P][j2 - 1] - input[P - 1][j1] + input[P++ - 1][j2 - 1];
                    area = (j1 - j2 + 1) * (i - P + 1); 
                    if (area > MaxArea) {
                        MaxArea = (j1 - j2 + 1) * (i - P + 1);
                        Cost = sum;
                    }
                    else if (area == MaxArea)
                        Cost = min(Cost, sum);
                }
            }
        }
        cout << "Case #" << C << ": " << MaxArea << ' ' << Cost << '\n';
    }
    return 0;
}

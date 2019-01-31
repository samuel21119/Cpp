/*************************************************************************
  > File Name: 11264 - Coin Collector.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jan 21 17:33:04 2018
*************************************************************************/

#include <iostream>
using namespace std;
int in[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        int coin, count, temp, sum;
        cin >> coin;
        for (int i = 0; i < coin; i++)
            cin >> in[i];
        count = 2;
        temp = in[coin - 1] - 1;
        sum = in[0];
        for (int i = 1; i < coin - 1; i++) {
            if (sum < in[i] && sum + in[i] < in[i + 1]) {
                count++;
                sum += in[i];
            }
        }
        cout << count << '\n';
    }
    return 0;
}

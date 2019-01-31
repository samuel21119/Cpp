/*************************************************************************
  > File Name: 1260 - Sales.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jan 26 13:28:55 2018
*************************************************************************/

#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, cnt;
    int input[1002];
    cin >> c;
    while (c--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> input[i];
        cnt = 0;
        for (int i = 1; i < n; i++) {
            int t = i;
            while (input[t - 1] <= input[t] && t >= 1) {
                swap(input[t-1], input[t]);
                t--;
            }
            cnt += i - t;
        }
        cout << cnt << '\n';
    }
    return 0;
}

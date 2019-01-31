/*************************************************************************
  > File Name: a263.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Apr  4 11:45:19 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool IfLeap(int a) {
    if (!(a % 400))
        return 1;
    if (!(a % 100))
        return 0;
    if (!(a % 4))
        return 1;
    return 0;
}
int month[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int year[10001];
int calc (int in[]) {
    int Month;
    int re = year[in[0]];
    if (IfLeap(in[0])) 
        Month = 1;
    else
        Month = 0;
    for (int i = 12; i > in[1]; i--)
        re -= month[Month][i];
    re -= month[Month][in[1]] - in[2];
    return re;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    year[0] = 366;
    for (int i = 1; i < 10000; i++)
        if (IfLeap(i))
            year[i] = year[i - 1] + 366;
        else
            year[i] = year[i - 1] + 365;
    int in[2][3];
    int sum[2];
    while (cin >> in[0][0] >> in[0][1] >> in[0][2] >> in[1][0] >> in[1][1] >> in[1][2]) {
        sum[0] = calc(in[0]);
        sum[1] = calc(in[1]);
        cout << abs(sum[0] - sum[1]) << '\n';
    }
}

/*************************************************************************
  > File Name: 10918 - Tri Tiling.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar 21 23:20:55 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int p[31];
int main() {
    int in;
    p[0] = 1;
    p[2] = 3;
    for (int i = 4; i <= 30; i += 2)
        p[i] = p[i - 2] * 4 - p[i - 4];
    while (cin >> in && in != -1)
        cout << (in & 1 ? 0 : p[in]) << '\n';
    return 0;
}

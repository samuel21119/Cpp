/*************************************************************************
  > File Name: 00640 - Self Numbers.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Jul 14 05:16:34 2018
*************************************************************************/

#include <bits/stdc++.h>
#define N 1000001
using namespace std;
int self[N];
int sum(int i) {
    if (i < 10)
        return i;
    return i % 10 + sum(i / 10);
}
void gen_self(int i) {
    for (int temp = sum(i) + i; temp < N && temp == self[temp]; temp = sum(i) + i)
        self[temp] = i, i = temp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < N; i++)
        self[i] = i;
    for (int i = 1; i < N; i++)
        gen_self(i);
    for (int i = 1; i < N; i++)
        if (self[i] == i)
            cout << i << '\n';
    return 0;
}

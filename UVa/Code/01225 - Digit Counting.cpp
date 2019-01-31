/*************************************************************************
  > File Name: 01225 - Digit Counting.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Sep  5 17:56:55 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int cnt[10];
void add(int i) {
    while (i) {
        cnt[i % 10]++;
        i /= 10;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n;
    cin >> c;
    while (c--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        while (n--)
            add(n + 1);
        for (int i = 0; i < 10; i++)
            cout << cnt[i] << (i != 9 ? ' ' : '\n');
    }
}

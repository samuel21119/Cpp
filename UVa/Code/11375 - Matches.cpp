/*************************************************************************
  > File Name: 11375 - Matches.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:31:03 2017
*************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
unsigned int a[2001][1000];
int len[2001];
char _size[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void add(int A, int B) {
    int lenA = len[A];
    int lenB = len[B];
    int maxlen = max(lenA, lenB);
    for (int i = 0; i <= maxlen; i++) {
        a[A][i] += a[B][i];
    }
    len[A] = maxlen;
    for (int i = 0; i <= maxlen; i++) {
        if (a[A][i] >= 100000000) {
            a[A][i + 1] += a[A][i] / 100000000;
            a[A][i] %= 100000000;
            if (i == maxlen)
                len[A]++;
        }
    }
}
void print(int in) {
    int tmp;
    int _len = len[in];
    for (int i = _len; i >= 0; i--) {
        if (i < _len) {
            tmp =  a[in][i];
            while (tmp < 10000000) {
                tmp *= 10;
                cout << 0;
            }
        }
        cout << a[in][i];
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int in;
    memset(a, 0, sizeof(a));
    memset(len, 0, sizeof(len));
    a[0][0] = 1;
    for (int i = 0; i < 2000; i++)
        for (int j = 0; j < 10; j++)
            if (!(i == 0 && j == 0) && i + _size[j] <= 2000)
                add(i + _size[j], i);
    a[6][0] += 1;
    for (int i = 2; i <= 2000; i++)
        add(i, i - 1);
    while (cin >> in)
        print(in);
    return 0;
}


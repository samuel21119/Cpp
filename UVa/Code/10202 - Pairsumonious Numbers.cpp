/*************************************************************************
  > File Name: 10202 - Pairsumonious Numbers.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan  1 10:44:58 2018
*************************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 0xcfffffff
using namespace std;
int n, inn, in[38], incp[38], re[10], use;
bool t;
void test() {
    for (int i = 0; i < inn; i++)
        incp[i] = in[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto t = find(incp, incp + inn, re[i] + re[j]);
            if (t == incp + inn)
                return;
            *t = MAX;
        }
    }
    sort(re, re + n);
    for (int i = 0; i < n - 1; i++)
        cout << re[i] << ' ';
    cout << re[n - 1] << '\n';
    t = true;
}
void choose(int index, int c) {
    if (index >= inn) return;
    if (c == n)
        test();
    else {
        re[c] = in[index] - re[0];
        if (index != use)
            choose(index + 1, c + 1);
        if (t) return;
        choose(index + 1, c);
    }
}
int main() {
    int a, b, c;
    while (cin >> n) {
        inn = n * (n - 1) / 2;
        for (int i = 0; i < inn; i++)
            cin >> in[i];
        sort(in, in + inn);
        a = in[0];
        b = in[1];
        t = false;
        for (int i = 2; i < inn; i++) {
            c = a + b - in[i];
            if (!(c % 2)) {
                c /= 2;
                re[0] = c;
                re[1] = a - c;
                re[2] = b - c;
                use = i;
                choose(2, 3);
                if (t) break;
            }
        }
        if (!t)
            cout << "Impossible\n";
    }
    return 0;
}

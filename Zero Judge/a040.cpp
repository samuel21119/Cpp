/*************************************************************************
  > File Name: a040.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar 14 21:55:15 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int pow (int a, int b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int tmp = pow(a, b >> 1);
    if (b & 1)
        return tmp * tmp * a;
    return tmp * tmp;
}
int powsum (int i) {
    int len = 0;
    int number[10];
    int sum = 0;
    while (i) {
        number[len++] = i % 10;
        i /= 10;
    }
    for (int i = 0; i < len; i++) 
        sum += pow(number[i], len);
    return sum;
}
int main() {
    int start, end;
    while (cin >> start >> end) {
        bool flag = 0;
        while (start <= end)
            if (powsum(start) == start++) {
                if (flag)
                    cout << ' ';
                cout << start - 1;
                flag = 1;
            }
        cout << (flag ? "\n" : "none\n");
    }
    return 0;
}

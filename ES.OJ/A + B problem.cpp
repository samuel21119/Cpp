/*************************************************************************
  > File Name: A + B problem.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Feb  1 12:39:21 2018
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char a[10000003], b[10000003];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int la, lb;
    la = lb = 0;
    char temp;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    while (1) {
        temp = getchar();
        if (temp == ' ')
            break;
        a[la++] = temp - '0';
    }
    while (1) {
        temp = getchar();
        if (temp == '\n')
            break;
        b[lb++] = temp - '0';
    }
    reverse(a, a + la);
    reverse(b, b + lb);
    int m = max(la, lb);
    for (int i = 0; i < m; i++) {
        if (i < la)
            b[i] += a[i];
        else
            break;
        if (b[i] > 9) {
            b[i] -= 10;
            b[i+1]++;
            if (i == m - 1)
                m++;
        }
    }
    for (int i = m - 1; i >= 0; i--) cout << (int)b[i];
    cout << '\n';
}

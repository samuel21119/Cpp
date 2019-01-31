/*************************************************************************
  > File Name: 12459 - Bees ancestors.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Jan 30 11:14:12 2018
*************************************************************************/

#include <iostream>
using namespace std;
unsigned long long int M[82], F[82];
int main() {
    int in;
    for (int i = 0; i < 82; i++) M[i] = F[i] = 0;
    F[1] = 1;
    F[2] = 1; M[2] = 1;
    for (int i = 3; i <= 80; i++) {
        F[i] = F[i - 1] + M[i - 1];
        M[i] = F[i - 1];
    }
    while (cin >> in && in) {
        cout << F[in] + M[in] << '\n';
    }
    return 0;
}


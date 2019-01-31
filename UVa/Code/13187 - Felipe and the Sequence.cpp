/*************************************************************************
  > File Name: 13187 - Felipe and the Sequence.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:38:36 2017
*************************************************************************/

#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long int a;
    int c;
    cin >> c;
    while (c--) {
        cin >> a;
        cout << (a + 1) * (a + 1) - 1 << '\n';
    }
    return 0;
}


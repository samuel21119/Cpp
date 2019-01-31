/*************************************************************************
  > File Name: 11000 - Bee.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Jul 14 17:20:19 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int male, female;
    int n;
    while (cin >> n && n != -1) {
        male = 0;
        female = 1;
        while (n--) {
            unsigned int tmp = male + 1;
            male += female;
            female = tmp;
        }
        cout << male << ' ' << female + male << '\n';
    }
    return 0;
}

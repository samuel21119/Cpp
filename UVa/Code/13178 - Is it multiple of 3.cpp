/*************************************************************************
  > File Name: 13178 - Is it multiple of 3.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:37:39 2017
*************************************************************************/

#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long a;
    int c;
    cin >> c;
    while (c--) {
        cin >> a;
        if (((a+1)*a/2) % 3)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}


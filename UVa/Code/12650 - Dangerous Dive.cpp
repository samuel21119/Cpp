/*************************************************************************
  > File Name: 12650 - Dangerous Dive.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:37:23 2017
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main() {
    int a, b, t;
    bool in[10002];
    while (cin >> a >> b) {
        memset(in, 1, sizeof(in));
        for (int i = 0; i < b; i++) {
            cin >> t;
            in[t] = 0;
        }
        if (a == b) {
            cout <<"*\n";
            continue;
        }
        for (int i = 1; i <= a; i++)
            if (in[i])
                cout << i << ' ';
        cout << '\n';
    }
    return 0;
}


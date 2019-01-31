/*************************************************************************
  > File Name: 13181 - Sleeping in hostels.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:37:58 2017
*************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char a[500000];
    while (cin >> a) {
        int x1, x2, x3, len, diff, i;
        x1 = x2 = -1;
        len = strlen(a);
        for (i = 0; i < len; i++) {
            if (a[i] != 'X')
                continue;
            if (x2 == -1) {
                x2 = 0;
                diff = i * 2;
            }
            else {
                if (diff <= i - x3) {
                    diff = i - x3;
                }
            }
            x3 = i;
            //cout << diff <<'\n';
        }
        diff = diff > (--i - x3) * 2 ? diff : (i - x3) * 2;
        cout << diff/2-1 << '\n';
    }
    return 0;
}


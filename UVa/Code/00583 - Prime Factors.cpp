/*************************************************************************
  > File Name: 00583 - Prime Factors.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Jul 12 15:43:32 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long input;
    while (cin >> input && input) {
        cout << input << " = ";
        bool out = 0;
        if (input < 0) {
            cout << -1;
            out = 1;
            input = -input;
        }
        if (input == 1) {
            cout << (out ? "\n" : "1\n");
            continue;
        }
        for (int i = 2; i <= sqrt(input); i++) {
            while (!(input % i)) {
                if (out)
                    cout << " x ";
                cout << i;
                out = 1;
                input /= i;
            }
        }
        if (input > 1)
            cout << (out ? " x " : "") << input;
        cout << '\n';
    }
    return 0;
}

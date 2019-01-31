/*************************************************************************
  > File Name: 10026 - Shoemakers Problem.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:39:26 2017
*************************************************************************/

#include <iostream>
#include <utility>
#include <algorithm>
#define F first
#define S second
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, in1, in2;
    pair<double, int> s[1002];
    cin >> c;
    while (c--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in1 >> in2;
            s[i].F = (double)in1 / (double)in2;
            s[i].S = i + 1;
        }
        sort(s, s + n);
        for (int i = 0, j = 1; i + j < n; i++) {
            if (s[i].F == s[j].F) {
                while (s[i].F == s[j].F && i + j < n)
                    s[i - 1 + j].F = s[i - 1 + j].S, j++;
                sort(s + i, s + j);
                i += j - 1;
                j = 1;
            }
        }
        for (int i = 0; i < n; i++)
            cout << s[i].S << ((i < n - 1) ? " " : "");
        if (c) cout << '\n';
        cout << '\n';
    }
    return 0;
}


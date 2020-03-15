/*************************************************************************
  > File Name: B.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jun 11 21:48:27 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    int ans = 0;
    char in[2001];
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i + p < n && !ans; i++) {
        if (in[i] == '.' || in[i + p] == '.') {
            if (in[i] == '1')
                in[i + p] = '0';
            else if (in[i] == '0')
                in[i + p] = '1';
            else {
                if (in[i + p] == '1')
                    in[i] = '0';
                else if (in[i + p] == '0')
                    in[i] = '1';
                if (in[i] == '.' && in[i + p] == '.') {
                    in[i + p] = '0';
                    in[i] = '1';
                }
            }
            ans = 1;
        }
    }
    if (ans == 0) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (in[i] == '.')
            cout << 0;
        else
            cout << in[i];
    }
    cout << '\n';
    return 0;
}

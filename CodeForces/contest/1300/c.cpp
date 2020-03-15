/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Feb 11 14:05:05 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[100000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int j = 30; j >= 0; j--) {
        int cnt = 0;
        int t;
        for (int i = 0; i < n; i++)
            if (in[i] & (1 << j))
                cnt++, t = i;
        if (cnt == 1) {
            cout << in[t];
            for (int i = 0; i < n; i++)
                if (i != t)
                    cout << ' ' << in[i];
            cout << '\n';
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        cout << in[i] << ' ';
    cout << '\n';
    return 0;
}

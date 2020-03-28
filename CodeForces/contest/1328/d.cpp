/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Mar 28 23:05:13 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[200010];
int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        bool same = 1;
        for (int i = 1; i < n; i++)
            same &= in[i] == in[i - 1];
        if (same) {
            cout << "1\n";
            for (int i = 0; i < n; i++)
                cout << "1 ";
            cout << '\n';
            continue;
        }
        if (n % 2 == 0) {
            cout << "2\n";
            for (int i = 0; i < n; i++)
                cout << (i % 2 + 1) << ' ';
            cout << '\n';
            continue;
        }
        int id = -1;
        for (int i = 0; i < n; i++)
            if (in[i] == in[(i + 1) % n]) {
                id = i;
                break;
            }
        if (id == -1) {
            cout << "3\n";
            cout << "3 ";
            for (int i = 1; i < n; i++)
                cout << i % 2 + 1 << ' ';
            cout << '\n';
            continue;
        }
        cout << "2\n";
        for (int i = 0; i <= id; i++)
            cout << i % 2 + 1 << ' ';
        for (int i = id + 1; i < n; i++)
            cout << ((i - 1) + 2) % 2 + 1 << ' ';
        cout << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Oct 25 22:45:54 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int in[200010];
int in2[200010];
bool out[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    for (int i = 1; i <= n; i++) {
        cin >> in2[i];
    }
    int last = 0;
    for (int i = 1; i <= n; i++) {
        int now = in2[i];
        if (out[now]) {
            cout << "0 ";
            continue;
        }
        int j;
        for (j = last; j < n; j++) {
            out[in[j]] = 1;
            if (in[j] == now)
                break;
        }
        cout << j - last << ' ';
        last = j;
    }
    return 0;
}

/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Aug 30 23:28:20 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t, n;
int in[110];
void Awin(bool x) {
    cout << (x ? "T" : "HL") << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> in[i];
        if (n == 1) {
            Awin(1);
            continue;
        }
        sort(in, in + n);
        int mx = in[n - 1];
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += in[i];
        if (sum < mx) {
            Awin(1);
        }else {
            Awin((sum + mx) % 2);
        }
    }
    
    return 0;
}

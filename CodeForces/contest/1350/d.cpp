/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon May 18 13:12:03 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
bool in[100010];
int k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        bool ok = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            if (t < k)
                in[i] = 0;
            else if (t > k)
                in[i] = 1;
            else
                in[i] = ok = 1;
        }
        if (ok) {
            ok = n == 1;
            for (int i = 0; i < n; i++)
                for (int j = 1; j <= 2 && i + j < n; j++)
                    if (in[i] && in[i + j])
                        ok = 1;
        }
        cout << (ok ? "yes" : "no") << '\n';
    }
    return 0;
}

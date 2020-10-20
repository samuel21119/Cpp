/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 21 06:27:26 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[5010];
bool connected[5010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            connected[i] = 0;
            cin >> in[i];
        }
        if (*max_element(in, in + n) == *min_element(in, in + n)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!(connected[j] && connected[i]) && in[i] != in[j]) {
                    connected[i] = connected[j] = 1;
                    cout << i + 1 << ' ' << j + 1 << '\n';
                }
            }
        }
    }
    return 0;
}

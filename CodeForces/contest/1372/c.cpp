/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Jul 11 23:31:19 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int in[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> in[i];
        int cnt = 0;
        int start = 1;
        int end = n;
        while (start <= n && start == in[start])
            start++;
        while (end > 0 && end == in[end])
            end--;
        if (start == n + 1) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = start; i <= end; i++) {
            if (i == in[i])
                cnt++;
        }
        cout << (cnt == 0 ? 1 : 2) << '\n';
    }
    return 0;
}

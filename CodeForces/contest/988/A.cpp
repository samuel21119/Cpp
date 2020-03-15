/*************************************************************************
  > File Name: A-2.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jun  1 22:49:55 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int input[101];
int n, k, cnt;
bool use[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        if (!use[input[i]]) {
            cnt++;
            use[input[i]] = 1;
        }
        else
            input[i] = -1;
    }
    if (cnt >= k)
        cout << "YES\n";
    else {
        cout << "NO\n";
        return 0;
    }
    cnt = 0;
    for (int i = 0; i < n && k; i++) {
        if (input[i] > 0) {
            if (cnt)
                cout << ' ';
            else
                cnt = 1;
            cout << i;
            k--;
        }
    }
    return 0;
}

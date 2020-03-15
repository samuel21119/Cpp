/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Aug  8 22:15:15 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
string a, b;
long long stat[4];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == '1') //1 1
                stat[0]++;
            else
                stat[1]++; // 0 0
        }else {
            if (a[i] == '1') // 1 0
                stat[2]++;
            else
                stat[3]++; // 0 1
        }
    }
    long long int ans = 0;
    ans = stat[0] * stat[1];
    ans += stat[2] * stat[1];
    ans += stat[2] * stat[3];
    cout << ans << '\n';
    return 0;
}

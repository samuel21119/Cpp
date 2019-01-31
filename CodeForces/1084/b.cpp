/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Dec 11 08:34:27 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, s, sum;
ll in[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        sum += in[i];
    }
    if (sum < s) {
        cout << "-1\n";
        return 0;
    }else if (sum == s) {
        cout << "0\n";
        return 0;
    }
    if (n == 1) {
        cout << in[0] - s;
        return 0;
    }
    sort(in, in + n);
    if (sum - in[0] * n >= s) {
        cout << in[0] << '\n';
        return 0;
    }
    ll re = s - sum + in[0] * n;
    re = re / n + (re % n ? 1 : 0);
    cout << in[0] - re;
    return 0;
}

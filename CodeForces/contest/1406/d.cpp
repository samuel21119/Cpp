/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep 20 11:10:30 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, q;
ll in[100010];
ll diff[100010];
ll toAdd;
ll getAns() {
    ll tmp = in[1] + toAdd;
    if (tmp > 0)
        return (tmp + 1) / 2;
    else
        return tmp / 2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
    }
    for (int i = 2; i <= n; i++) {
        diff[i] = in[i] - in[i - 1];
        if (diff[i] > 0)
            toAdd += diff[i];
    }
    cout << getAns() << '\n';
    cin >> q;
    while (q--) {
        int a, b, x;
        cin >> a >> b >> x;
        if (a == 1)
            in[1] += x;
        else {
            if (diff[a] > 0)
                toAdd -= diff[a];
            diff[a] += x;
            if (diff[a] > 0)
                toAdd += diff[a];
        }

        if (b++ < n) {
            if (diff[b] > 0)
                toAdd -= diff[b];
            diff[b] -= x;
            if (diff[b] > 0)
                toAdd += diff[b];
        }
        cout << getAns() << '\n';
    }
    return 0;
}

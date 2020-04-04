/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Apr  3 23:06:10 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
ll sum;
int in[100010], in2[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> in[i];
        sum += in[i];
        in2[i] = in[i];
    }
    sum -= n;
    if (sum < 0) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < m && sum > 0; i++) {
        ll mn = min((ll)in[i] - 1, sum);
        in2[i] -= mn;
        sum -= mn;
    }
    int last = 1;
    vector<int> a;
    a.emplace_back(1);
    for (int i = 1; i < m; i++) {
        last += in2[i - 1];
        if (last + in[i] - 1 > n) {
            cout << "-1\n";
            return 0;
        }
        a.emplace_back(last);
    }
    for (int i : a)
        cout << i << ' ';
    return 0;
}

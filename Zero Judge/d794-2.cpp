/*************************************************************************
  > File Name: d794-2.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Aug 14 14:27:20 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int BIT[100010];
int n;
void add(int i) {
    while (i <= n) {
        BIT[i]++;
        i += i & -i;
    }
}
int query(int i) {
    int rank = 0;
    while (i) {
        rank += BIT[i];
        i -= i & -i;
    }
    return rank;
}
typedef unsigned long long ull;
ull in[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        vector<ull> vec;
        vec.resize(n);
        for (int i = 0 ; i < n; i++) {
            cin >> in[i];
            vec[i] = in[i];
        }
        memset(BIT, 0, sizeof(BIT));
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; i++)
            in[i] = lower_bound(vec.begin(), vec.end(), in[i]) - vec.begin() + 1;
        for (int i = 0; i < n; i++) {
            cout << i + 1 - query(in[i]) << '\n';
            add(in[i]);
        }

    }
    return 0;
}

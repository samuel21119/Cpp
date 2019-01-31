/*************************************************************************
  > File Name: 11727 - Cost Cutting.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jan 27 19:57:41 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, in[3];
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> in[0] >> in[1] >> in[2];
        sort(in, in + 3);
        cout << "Case " << i << ": " << in[1] << '\n';
    }
    return 0;
}

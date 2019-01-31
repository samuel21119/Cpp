/*************************************************************************
  > File Name: 11479 - Is this the easiest problem?.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jun 13 20:56:34 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long in[3];
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        cin >> in[0] >> in[1] >> in[2];
        sort(in, in + 3);
        if (!((in[1] - in[0]) < in[2] && in[2] < (in[0] + in[1]))) {
            cout << "Case " << i << ": Invalid\n";
            continue;
        }
        if (in[0] == in[1] && in[1] == in[2]) {
            cout << "Case " << i << ": Equilateral\n";
            continue;
        }
        if (in[0] == in[1] || in[1] == in[2] || in[0] == in[2]) {
            cout << "Case " << i << ": Isosceles\n";
            continue;
        }
        cout << "Case " << i << ": Scalene\n";
    }
    return 0;
}

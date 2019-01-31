/*************************************************************************
  > File Name: 10976 - Fractions Again.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jan 26 14:20:06 2018
*************************************************************************/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int check(int a, int b) {
    int t = b - a;
    int t2 = a * b;
    if (t2 % t)
        return 0;
    return t2/t;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, cnt, tmp;
    while (cin >> k) {
        cnt = 0;
        vector<pair<int, int> > v;
        for (int y = k * 2; y > k; y--) {
            tmp = check(k, y);
            if (tmp) {
                v.push_back(make_pair(tmp, y));
                cnt++;
            }
        }
        cout << cnt << '\n';
        while (cnt--) {
             cout << "1/" << k << " = 1/" << v[cnt].first << " + 1/" << v[cnt].second << '\n';
        }
    }
    return 0;
}

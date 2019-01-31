/*************************************************************************
  > File Name: 11286 - Conformity.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Jan  2 18:19:08 2018
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n) {
        map<long long,  int> m;
        int in[5], _max = 1, count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++)
                cin >> in[j];
            sort(in, in + 5);
            long long a = 0;
            for (int j = 0; j < 5; j++) {
                a *= 1000;
                a += in[j];
            }
            _max = max(_max, m[a] += 1);
        }
        for (auto it = m.begin(); it != m.end(); it++)
            if (_max == it->second)
                count += _max;
        cout << count << '\n';
    }
    return 0;
}

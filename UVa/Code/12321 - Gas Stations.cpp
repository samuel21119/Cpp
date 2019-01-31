/*************************************************************************
  > File Name: 12321 - Gas Stations.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Feb  3 17:37:54 2018
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> gas[10001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int road, g, x, r;
    while (cin >> road >> g && road) {
        for (int i = 0; i < g; i++) {
            cin >> x >> r;
            gas[i] = {x - r, x + r};
            if (gas[i].first < 0) gas[i].first = 0;
            if (gas[i].second > road) gas[i].second = road;
        }
        sort(gas, gas + g);
        int rans = 0, r = 0;
        for (int i = 0; r < road;) {
            int temp = r;
            while (i < g && gas[i].first <= r)
                temp = max(temp, gas[i++].second);
            if (temp == r)
                break;
            r = temp;
            rans++;
        }
        if (r < road)
            cout << "-1\n";
        else
            cout << g - rans << '\n';
    }
    return 0;
}

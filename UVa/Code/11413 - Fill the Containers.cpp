/*************************************************************************
  > File Name: 11413 - Fill the Containers.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Feb  4 16:37:55 2018
*************************************************************************/

#include <iostream>
using namespace std;
int vessels[1001];
int main() {
    int n, m, l, r, mid, sum, cnt;
    while (cin >> n >> m) {
        l = r = 0;
        for (int i = 0; i < n; i++) {
            cin >> vessels[i];
            r += vessels[i];
            l = max(l, vessels[i]);
        }
        while (l < r) {
            mid = (l + r) >> 1;
            sum = 0;
            cnt = 1;
            for (int i = 0; i < n; i++) {
                if (sum + vessels[i] <= mid)
                    sum += vessels[i];
                else {
                    cnt++;
                    sum = vessels[i];
                }
            }
            if (cnt > m)
                l = mid + 1;
            else
                r = mid;
        }
        cout << r << '\n';
    }
}

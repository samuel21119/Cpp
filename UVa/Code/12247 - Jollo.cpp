/*************************************************************************
  > File Name: 12247 - Jollo.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jan  3 16:54:28 2018
*************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int take[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
bool use[53];
int test(int a[], int x, int y) {
    for (int i = 1; i <= 52; i++) {
        if (use[i])
            continue;
        int _min = 3;
        for (int j = 0; j < 6; j++) {
            int c = 0;
            if (a[take[j][0]] < x)
                c++;
            if (a[take[j][1]] < y)
                c++;
            if (a[take[j][2]] < i)
                c++;
            _min = min(c, _min);
        }
        if (_min >= 2)
            return i;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[3], x, y;
    while (cin >> a[0] >> a[1] >> a[2] >> x >> y) {
        sort(a, a + 3);
        if (!a[2])
            break;
        memset(use, false, sizeof(use));
        use[a[0]] = use[a[1]] = use[a[2]] = use[x] = use[y] = true;
        cout << test(a, x, y) << '\n';
    }
    return 0;
}

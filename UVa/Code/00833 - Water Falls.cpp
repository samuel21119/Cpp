/*************************************************************************
  > File Name: 833 - Water Falls.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Dec 31 23:38:33 2017
*************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
struct line {
    int sx, sy, ex, ey;
};
bool inrange(int x, int sx, int ex) {
    return (sx <= x && x <= ex) || (sx >= x && x >= ex);
}
int main() {
    int x, y, ns, np, c, j;
    double _max, tmpy;
    cin >> c;
    while (c--) {
        cin >> np;
        line l[np];
        for (int i = 0; i < np; i++)
            cin >> l[i].sx >> l[i].sy >> l[i].ex >> l[i].ey;
        cin >> ns;
        while (ns--) {
            cin >> x >> y;
            while (true) {
                _max = -1;
                j = -1;
                for (int i = 0; i < np; i++) {
                    if (inrange(x, l[i].sx, l[i].ex)) {
                        tmpy = l[i].sy + (double)(l[i].sy - l[i].ey)*(x - l[i].sx)/(l[i].sx - l[i].ex);
                        if (tmpy < y && tmpy > _max) {
                            j = i;
                            _max = tmpy;
                        }
                    }
                }
                if (j == -1)
                    break;
                if (((double)(l[j].sy - l[j].ey) * (l[j].sx - l[j].ex)) > 0)
                    x = min(l[j].sx, l[j].ex);
                else
                    x = max(l[j].sx, l[j].ex);
                y = min(l[j].sy, l[j].ey);
            }
            cout << x << '\n';
        }
        if (c)
            cout << '\n';
    }
    return 0;
}

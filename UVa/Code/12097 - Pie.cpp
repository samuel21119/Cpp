/*************************************************************************
  > File Name: 12097 - Pie.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:36:34 2017
*************************************************************************/

#include <cstdio>
#include <cmath>
const double pi = 2 * asin(1);
int rr[10000];
int f, p;
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int c, t, pie;
    double up, dn, mid;
    scanf("%d", &c);
    while (c--) {
        scanf("%d%d", &p, &f);
        up = 0;
        dn = 0;
        f++;
        for (int i = 0; i < p; i++) {
            scanf("%d", &t);
            rr[i] = t * t;
          //  up = up > rr[i] ? up : rr[i];
            up = max(up, rr[i]);
        }
        while (up - dn > 0.00000001) {
            pie = 0;
            mid = (up + dn) / 2.0;
            for (int i = 0; i < p; i++)
                pie += rr[i] / mid;
            if (pie >= f)
                dn = mid;
            else
                up = mid;
        }
        printf("%.4f\n", dn * pi);
    }
    return 0;
}


/*************************************************************************
  > File Name: 10034 - Freckles.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:40:41 2017
*************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
    double x, y;
}n[101], ed[4952];
double e[4952];
double s(double a) {return a*a;}
int p[102], r[4952];

bool cmp(int i, int j) {return e[i] < e[j];}
int find(int a) {return p[a] == a ? a : p[a] = find(p[a]);}
int main() {
    int c, v, E;
    double ans;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &v);
        for (int i = 0; i < v; i++)
            scanf("%lf%lf", &n[i].x, &n[i].y);
        E = 0;
        for (int i = 0; i < v - 1; i++)
            for (int j = i + 1; j < v; j++) {
                e[E] = sqrt(s(n[i].x - n[j].x) + s(n[i].y - n[j].y));
                ed[E].x = i; ed[E++].y = j;
            }
        for (int i = 0; i < v; i++)
            p[i] = i;
        for (int i = 0; i < E; i++)
            r[i] = i;
        sort(r, r+E, cmp);
        ans = 0;
        for (int i = 0; i < E; i++) {
            int x = find(ed[r[i]].x);
            int y = find(ed[r[i]].y);
            if (x != y) {
                ans += e[r[i]];
                p[x] = y;
            }
        }
        printf("%.2lf\n", ans);
        if (c)
            printf("\n");
    }
    return 0;
}


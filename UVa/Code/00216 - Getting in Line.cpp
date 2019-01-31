/*************************************************************************
  > File Name: 216 - Getting in Line.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jan 26 11:07:13 2018
*************************************************************************/

#include <cstdio>
#include <cmath>
using namespace std;

int x[9], y[9];
int path[9], now, _min_path[9];
int dots;
bool use[9];
double _min;
void dfs(int index, double sum, int p[]) {
    double t;
    int X, Y, X2, Y2;
    if (index == dots) {
        if (sum < _min) {
            for (int i = 0; i < dots; i++)
                _min_path[i] = p[i];
            _min = sum;
        }
        return;
    }
    if (sum > _min)
        return;
    X = x[path[index-1]]; Y = y[path[index-1]];
    for (int i = 0; i < dots; i++) {
        if (use[i])
            continue;
        X2 = x[i]; Y2 = y[i];
        t = sqrt((X-X2) * (X-X2) + (Y-Y2) * (Y - Y2));
        p[index] = i;
        use[i] = 1;
        dfs(index + 1, sum + t + 16.0, p);
        use[i] = 0;
    }
}
int main() {
    int c = 1, X1, X2, Y1, Y2, round;
    double t;
    while (1) {
        scanf("%d", &dots);
        if (!dots)
            break;
        printf("**********************************************************\nNetwork #%d\n", c++);
        for (int i = 0; i < dots; i++) {
            scanf("%d%d", x + i, y + i);
            use[i] = 0;
        }
        _min = 100000000;
        for (int i = 0; i < dots; i++) {
            path[0] = i;
            use[i] = 1;
            dfs(1, 0, path);
            use[i] = 0;
        }
        round = _min * 100 + 0.5;
        for (int i = 1; i < dots; i++) {
            X1 = x[_min_path[i-1]]; Y1 = y[_min_path[i-1]];
            X2 = x[_min_path[i]]; Y2 = y[_min_path[i]];
            t = sqrt((X1-X2) * (X1-X2) + (Y1-Y2) * (Y1 - Y2)) + 16.0;
            t = (int)(t * 100 + 0.5); t /= 100;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", X1, Y1, X2, Y2, t);
        }
        printf("Number of feet of cable required is %.2lf.\n", (double)round/100);
    }
    return 0;
}

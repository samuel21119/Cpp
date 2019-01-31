/*************************************************************************
  > File Name: 10099 - The Tourist Guide.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:55:26 2017
*************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
struct link{
    int f, s, t;
};
int main() {
    int n, r, s, e, vis, trip[102], c = 1;
    while (cin >> n >> r) {
        if (!(n + r))
            break;
        link l[r];
        for (int i = 0; i < r; i++)
            cin >> l[i].f >> l[i].s >> l[i].t;
        cin >> s >> e >> vis;
        for (int i = 0; i < r; i++) {
            l[i].t -= 1;
            if (vis % l[i].t > 0)
                l[i].t = vis / l[i].t + 1;
            else
                l[i].t = vis / l[i].t;
        }
        for (int i = 1; i <= n; i++)
            trip[i] = -1;
        trip[s] = 0;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < r; i++) {
                if (trip[l[i].f] != -1) {
                    if (trip[l[i].s] == -1) {
                        trip[l[i].s] = max(l[i].t, trip[l[i].f]);
                        flag = true;
                    }
                    else if (trip[l[i].s] > max(l[i].t, trip[l[i].f])) {
                        trip[l[i].s] = l[i].t;
                        flag = true;
                    }
                }
                if (trip[l[i].s] != -1) {
                    if (trip[l[i].f] == -1) {
                        trip[l[i].f] = max(l[i].t, trip[l[i].s]);
                        flag = true;
                    }
                    else if (trip[l[i].f] > max(l[i].t, trip[l[i].s])) {
                        trip[l[i].f] = max(l[i].t, trip[l[i].s]);
                        flag = true;
                    }
                }
            }
        }
        cout << "Scenario #" << c++ <<"\nMinimum Number of Trips = " << trip[e] << "\n\n";
    }
    return 0;
}


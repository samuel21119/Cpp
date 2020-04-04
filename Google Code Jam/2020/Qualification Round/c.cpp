/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Apr  4 10:31:20 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct E {
    int start, end;
    int id;
    E() {}
    E(int a, int b, int c) {
        start = a, end = b, id = c;
    }
    bool operator< (const E &b) const {
        if (start == b.start)
            return end < b.end;
        return start < b.start;
    }
}events[1010];
int n, C, J, im;
char ans[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        ans[n] = '\0';
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            events[i] = {a, b, i};
        }
        sort(events, events + n);
        C = J = -1;
        im = 0;
        for (int i = 0; i < n; i++) {
            int start = events[i].start;
            int end = events[i].end;
            int id = events[i].id;
            if (start >= C) {
                C = end;
                ans[id] = 'C';
            }else if (start >= J) {
                J = end;
                ans[id] = 'J';
            }else {
                im = 1;
                break;
            }
        }
        cout << "Case #" << t << ": ";
        if (im)
            cout << "IMPOSSIBLE";
        else
            cout << ans;
        cout << '\n';
    }
    return 0;
}

/*
4
3
360 480
420 540
600 660
3
0 1440
1 3
2 4
5
99 150
1 100
100 301
2 5
150 250
2
0 720
720 1440*/

/*
Case #1: CJC
Case #2: IMPOSSIBLE
Case #3: JCCJJ
Case #4: CC*/

/*************************************************************************
  > File Name: 10067 - Playing with Wheels.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:49:03 2017
*************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
int scan() {
    int a[4];
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}
int calc(int i, int index) {
    char a[4];
    int op = 1;
    if (index > 4) index -= 4, op = -1;
    for (int j = 3; j >= 0; j--) {
        a[j] = i % 10;
        if (j + 1 == index)
            a[j] += op;
        if (a[j] > 9)
            a[j] = 0;
        if (a[j] < 0)
            a[j] = 9;
        i /= 10;
    }
    return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, s, e, b, next;
    cin >> c;
    while (c--) {
        s = scan();
        e = scan();
        int run[10000];
        for (int i = 1; i <= 9999; i++)
            run[i] = -1;
        run[s] = 0;
        cin >> b;
        for (int i = 0; i < b; i++)
            run[scan()] = 0;
        queue<int> que;
        que.push(s);
        while (que.size() >= 1) {
            b = que.front();
            que.pop();
            if (b == e)
                break;
            for (int i = 1; i <= 8; i++) {
                next = calc(b, i);
                if (run[next] != -1)
                    continue;
                que.push(next);
                run[next] = run[b] + 1;
            }
        }
        cout << run[e] << '\n';
    }
    return 0;
}


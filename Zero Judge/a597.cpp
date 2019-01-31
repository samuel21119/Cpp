#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int n, m;
char in[501][501];
struct p {
    int i, j;
};
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
queue<p> que;
int BFS(int i, int j) {
    p now, next;
    now.i = i;
    now.j = j;
    que.push(now);
    int count = 1;
    while (que.size()) {
        now = que.front();
        in[now.i][now.j] = 'X';
        que.pop();
        for (int a = 0; a < 4; a++) {
            next.i = now.i + di[a];
            next.j = now.j + dj[a];
            if (next.i >= 0 && next.j >= 0 && next.i < m && next.j < n) {
                if (in[next.i][next.j] == 'J') {
                    in[next.i][next.j] = 'X';
                    que.push(next);
                    count++;
                }
            }
        }
    }
    return count;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(cin >> m) {
        cin >> n;
        int count, MAX;
        count = MAX = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> in[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (in[i][j] == 'J') {
                    MAX = max(BFS(i, j), MAX);
                    count++;
                }
            }
        }
        cout << count << " " << MAX << '\n';
    }
}

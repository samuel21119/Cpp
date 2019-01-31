/*************************************************************************
  > File Name: 00429 - Word Transformation.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Apr 25 22:58:44 2018
*************************************************************************/

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

bool check(int x, int y, vector<string> &v) {
    int cnt = 0;
    int len = v[x].length();
    for (int i = 0; i < len; i++)
        if (v[x][i] != v[y][i])
            cnt++;
    if (cnt == 1)
        return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, len;
    int moves[210];
    string in;
    char a[25];
    cin >> c;
    while (c--) {
        vector<string> vec[11];
        while (1) {
            cin >> in;
            if (in[0] == '*')
                break;
            vec[in.length()].pb(in);
        }
        cin.get();
        while (cin.getline(a, 25)) {
            if (a[0] == '\0')
                break;
            cout << a << ' ';
            int i = 1;
            while (a[i] != ' ') i++;
            a[i] = '\0';

            string _start(a);
            string _end(a + i + 1);
            len = _start.length();
            int Start = find(vec[len].begin(), vec[len].end(), _start) - vec[len].begin();
            int End = find(vec[len].begin(), vec[len].end(), _end) - vec[len].begin();
            queue<int> que;
            int cur;
            int vecLen = vec[len].size();
            for (int i = 0; i <= vecLen; i++) moves[i] = -1;
            moves[Start] = 0;
            que.push(Start);

            while (!que.empty()) {
                cur = que.front();
                que.pop();
                if (cur == End)
                    break;
                for (int i = 0; i < vecLen; i++) {
                    if (check(i, cur, vec[len]) || moves[i] != -1)
                        continue;
                    que.push(i);
                    moves[i] = moves[cur] + 1;
                }
            }
            cout << moves[End] << '\n';
        }
        if (c)
            cout << '\n';
    }
}

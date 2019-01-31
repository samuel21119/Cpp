/*************************************************************************
  > File Name: 11730 - Number Transformation.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 10 20:21:32 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001], prime;
bool p[1001];
int visit[1001];
int s, e, cur, cnt, t;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    prime.emplace_back(2);
    for (int i = 3; i <= 1000; i += 2)
        if (!p[i]) {
            prime.emplace_back(i);
            for (int j = i << 1; j <= 1000; j += i)
                p[j] = 1;
        }
    for (int i = 2; i < 1000; i++)
        for (int &j : prime) {
            if (i <= j || i + j > 1000)
                break;
            if (!(i % j))
                graph[i].emplace_back(j + i);
        }
    while (cin >> s >> e && s) {
        cout << "Case " << ++t << ": ";
        if (s > e) {
            cout << "-1\n";
            continue;
        }
        if (s == e) {
            cout << "0\n";
            continue;
        }
        queue<int> q;
        q.push(s);
        memset(visit, 0, sizeof(visit));
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur == e)
                break;
            for (int &i : graph[cur]) {
                if (i == s || visit[i])
                    continue;
                visit[i] = visit[cur] + 1;
                q.push(i);
            }
        }
        cout << (visit[e] ? visit[e] : -1) << '\n';
    }
    return 0;
}

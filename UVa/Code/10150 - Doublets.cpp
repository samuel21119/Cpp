/*************************************************************************
  > File Name: 10150 - Doublets.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Oct  9 21:58:20 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string in[25143];
map<string, int> m;
vector<int> graph[25143];
int n, s, e, cur, next, now;
int trace[25143], visit[25143];
bool ans;
string tmp1, tmp2;
bool connect(const string &i, const string &j) {
    if (i.length() != j.length())
        return 0;
    int cnt = 0;
    for (unsigned int k = 0; k < i.length() && cnt < 2; k++)
        cnt += i[k] != j[k];
    return cnt == 1;
}
inline void print() {
    stack<int> tmp;
    while (e != s) {
        tmp.push(e);
        e = trace[e];
    }
    cout << in[s] << '\n';
    while (!tmp.empty()) {
        cout << in[tmp.top()] << '\n';
        tmp.pop();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (getline(cin, tmp1)) {
        if (tmp1[0] == '\0')
            break;
        in[n] = tmp1;
        m[tmp1] = n++;
        assert(n <= 25143);
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (connect(in[i], in[j])) {
                graph[i].emplace_back(j);
                graph[j].emplace_back(i);
            }
    while (cin >> tmp1 >> tmp2) {
        s = m[tmp1];
        e = m[tmp2];
        ans = 0;
        visit[s] = ++now;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur == e) {
                ans = 1;
                break;
            }
            for (int &i : graph[cur]) {
                if (visit[i] == now)
                    continue;
                visit[i] = now;
                trace[i] = cur;
                q.push(i);
            }
        }
        if (now > 1)
            cout << '\n';
        if (ans)
            print();
        else
            cout << "No solution.\n";
    }
    return 0;
}

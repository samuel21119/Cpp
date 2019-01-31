/*************************************************************************
  > File Name: c455.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Aug 22 12:32:31 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int match[maxn], trace[maxn], visit[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        int x, y, k, ans = 0;
        cin >> x >> y >> k;
        vector<int> edge[maxn];
        while (k--) {
            int a, b;
            cin >> a >> b;
            edge[a].emplace_back(x + b);
            edge[x + b].emplace_back(a);
        }
        memset(match, 0, sizeof(match));
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i <= x; i++)
            if (!match[i]) {
                queue<int> q;
                q.push(i);
                trace[i] = 0;
                bool flag = 1;
                while (!q.empty() && flag) {
                    int cur = q.front();
                    q.pop();
                    for (int j : edge[cur]) {
                        if (visit[j] == i)
                            continue;
                        visit[j] = i;
                        //cout << match[j] << endl;
                        q.push(match[j]);
                        if (match[j])
                            trace[match[j]] = cur;
                        else {
                            flag = 0;
                            int a, b;
                            a = cur; b = j;
                            while (a) {
                                int tmp = match[a];
                                match[a] = b;
                                match[b] = a;
                                a = trace[a];
                                b = tmp;
                            }
                        }
                        if (!flag)
                            break;
                    }
                }
                if (match[i])
                    ans++;
            }
        cout << ans << '\n';
    }
    return 0;
}

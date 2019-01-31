/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep  2 23:23:30 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
set<int> link[200001];
bool visit[200001];
int in[200001], current;
int cnt[200001];
int n, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        a--; b--;
        link[a].insert(b);
        link[b].insert(a);
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        in[i]--;
    }
    queue<int> q;
    q.push(in[0]);
    bool ans = 1;
    int j = 0;
    if (in[0] != 0) {
        cout << "No\n";
        return 0;
    }
    visit[in[0]] = 1;
    while (!q.empty() && j < n - 1) {
        current = q.front();
        q.pop();
        while (cnt[current]--) {
            j++;
            if (link[current].find(in[j]) != link[current].end() && !visit[in[j]]) {
                q.push(in[j]);
                visit[in[j]] = 1;
                cnt[in[j]]--;
            }
            else {
                ans = 0;
                break;
            }
        }
    }
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}

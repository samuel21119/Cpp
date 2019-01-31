/*************************************************************************
  > File Name: b583.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Dec 13 09:05:28 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, t, a, b;
int cnt[maxn];
bool ans;
int visit;
vector<int> link[maxn];
int que[maxn], l, r;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            link[i].clear();
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        while (m--) {
            cin >> a >> b;
            ans |= a == b;
            cnt[b]++;
            link[a].emplace_back(b);
        }
        if (ans) {
            cout << "O______O\n";
            continue;
        }
        l = r = 0;
        for (int i = 1; i <= n; i++)
            if (!cnt[i])
                que[r++] = i;
        visit = n;
        while (l != r) {
            int cur = que[l++];
            visit--;
            for (int &j : link[cur]) {
                cnt[j]--;
                if (!cnt[j])
                    que[r++] = j;
            }
        }
        cout << (visit ? "O______O" : "W+W" ) << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: e.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Mar 16 18:46:25 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> prime;
bool p[1000000];
int in[2];
vector<int> link[1000010];
int mx, ans;
int dis[1000010];
int vis[1000010], ptr;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    prime.emplace_back(1);
    prime.emplace_back(2);
    for (int i = 3; i < 1000000; i++) {
        if (p[i])
            continue;
        for (int j = i * 2; j < 1000000; j += i)
            p[j] = 1;
        prime.emplace_back(i);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        in[0] = in[1] = -1;
        for (int j = 1; prime[j] * prime[j] <= x; j++) {
            if (x % prime[j])
                continue;
            bool add = 0;
            while (x % prime[j] == 0) {
                add ^= 1;
                x /= prime[j];
            }
            if (add) {
                in[1] = in[0];
                in[0] = prime[j];
            }
        }
        if (x > 1) {
            in[1] = in[0];
            in[0] = x;
        }
        if (in[1] != -1) {
            link[in[0]].emplace_back(in[1]);
            link[in[1]].emplace_back(in[0]);
        }else if (in[0] != -1) {
            link[1].emplace_back(in[0]);
            link[in[0]].emplace_back(1);
        }else {
            cout << "1\n";
            return 0;
        }
    }
    ans = 1e9;
    for (int i = 0; prime[i] * prime[i] <= mx; i++) {
        dis[prime[i]] = 0;
        queue<pair<int, int>> q;
        q.push({prime[i], prime[i]});
        vis[prime[i]] = ++ptr;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            bool from = 0;
            for (auto k : link[cur.first]) {
                if (!from && k == cur.second) {
                    from = 1;
                    continue;
                }
                if (vis[k] == ptr) {
                    ans = min(ans, dis[cur.first] + dis[k] + 1);
                    break;
                }else {
                    vis[k] = ptr;
                    dis[k] = dis[cur.first] + 1;
                    q.push({k, cur.first});
                }
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
    return 0;
}

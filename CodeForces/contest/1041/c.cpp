#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int n, m, d, in;

int ans[200001];
int cnt = 1;
int re;
set<int> s;
map<int, int> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        cin >> in;
        M[in] = i;
        s.insert(in);
    }
    while (!s.empty()) {
        auto it = s.begin();
        int now = *it;
        ans[M[now]] = cnt;
        s.erase(now);
        while ((it = s.upper_bound(now + d)) != s.end()) {
            now = *it;
            ans[M[now]] = cnt;
            s.erase(now);
        }
        cnt++;
    }
    cout << cnt - 1 << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
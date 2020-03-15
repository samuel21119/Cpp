#include<bits/stdc++.h>
using namespace std;
int n, r;
bool in[1010];
bool p[1010];
int check(int i) {
    int re = -1;
    for (int j = max(0, i - r + 1); j < n && j <= i + r - 1; j++)
        if (in[j])
            re = max(re, j);
    return re;
}
void doo(int i) {
    for (int j = i; j <= i + r - 1 && j < n; j++)
        p[j] = 1;
    for (int j = i; j >= i - r + 1 && j >= 0; j--)
        p[j] = 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!p[i]) {
            int tmp = check(i);
            if (tmp == -1) {
                cout << -1;
                return 0;
            }
            ans++;
            doo(tmp);
        }
    }
    cout << ans;
    return 0;
}

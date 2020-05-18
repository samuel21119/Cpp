/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Apr  9 01:21:07 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k, c;
string s;
bool in[3010];
vector<int> check;
vector<vector<int>> ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        in[i] = s[i] == 'R';
    }
    int mx_move = 0;
    for (int i = n - 1, cnt = 0; i >= 0; i--) {
        if (in[i]) {
            c += (n - 1) - i - cnt;
            mx_move = max(mx_move, (n - 1) - i - cnt);
            cnt++;
        }
    }
    if (c < k || mx_move > k) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        if (in[i] > in[i + 1])
            check.emplace_back(i);
    }
    ans.resize(k);
    for (int i = 0; i < k; i++) {
        vector<int> transfer;
        int t = k - i;
        while (!check.empty() && c >= t) {
            int now = check.back();
            swap(in[now], in[now + 1]);
            c--;
            ans[i].emplace_back(now);
            if (now + 2 < n && in[now + 1] > in[now + 2])
                transfer.emplace_back(now + 1);
            if (now - 1 >= 0 && in[now - 1] > in[now])
                transfer.emplace_back(now - 1);
            check.pop_back();
        }
        while (!transfer.empty()) {
            check.emplace_back(transfer.back());
            transfer.pop_back();
        }
    }
    if (c == 0) {
        for (int i = 0; i < k; i++) {
            cout << ans[i].size() << ' ';
            for (int j = ans[i].size() - 1; j >= 0; j--)
                cout << ans[i][j] + 1 << ' ';
            cout << '\n';
        }
    }else
        cout << -1;
    return 0;
}

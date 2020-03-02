/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Mar  2 18:16:27 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;


vector<int> num[26];
char in[101];
int n, ans;
int find_next(int x, int dir, char target) {
    for (int i = x + dir; i >= 0 && i < n; i += dir) {
        if (in[i] == 0)
            continue;
        if (in[i] == target) {
            return i;
        }
        return 1000;
    }
    return 1000;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        num[in[i] - 'a'].emplace_back(i);
    }
    for (char c = 'z'; c > 'a'; c--) {
        for (int i : num[c - 'a']) {
            int next1 = find_next(i, +1, c - 1);
            int next2 = find_next(i, -1, c - 1);
            if (next1 * next2 != 1000000) {
                in[i] = 0, ans++;
                if (next1 != 1000) {
                    int t = i;
                    while (t >= 0 && (t = find_next(t, -1, c)) != 1000) {
                        ans++;
                        in[t] = 0;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

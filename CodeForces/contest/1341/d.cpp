/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Apr 23 23:51:54 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string data1[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string in[2010];
int calc(string &s, int i) {
    int cnt = 0;
    for (int j = 0; j < 7; j++) {
        if (data1[i][j] == '0' && s[j] == '1') {
            return -1;
        }
        if (data1[i][j] == '1' && s[j] == '0')
            cnt++;
    }
    return cnt;
}
int diff(string &s) {
    int re = 100;
    for (int i = 0; i < 10; i++) {
        int cnt = calc(s, i);
        if (cnt != -1)
            re = min(re, cnt);
    }
    return re;
}
bool vis[2010][2010];
int n, k;
int sum[2010];
int dfs(int now, int used, string s) {
    if (k - used < sum[now])
        return 0;
    if (now >= n) {
        if (used == k) {
            cout << s << endl;
            exit(0);
        }
        return 0;
    }
    if (used > k) {
        return 0;
    }
    if (vis[now][used])
        return 0;
    vis[now][used] = 1;
    for (int i = 9; i >= 0; i--) {
        int c = calc(in[now], i);
        if (c == -1)
            continue;
        dfs(now + 1, used + c, s + char(i + '0'));
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = n - 1; i >= 0; i--) {
        int x = diff(in[i]);
        sum[i] = x;
        sum[i] += sum[i + 1];
    }
    dfs(0, 0, "");
    cout << -1;
    return 0;
}

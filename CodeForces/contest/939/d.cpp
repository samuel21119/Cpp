/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Sep  9 16:00:27 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

char s1[100005], s2[100005];
int parent[27];
int n, ans;
vector<char> v[27];

int p(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = p(parent[i]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> (s1 + 1) >> (s2 + 1);
    for (int i = 0; i < 27; i++)
        parent[i] = i;
    for (int i = 1; i <= n; i++) {
        if (s1[i] != s2[i])
            parent[p(s1[i] - 'a' + 1)] = p(s2[i] - 'a' + 1);
    }
    for (int i = 1; i < 27; i++)
        v[p(i)].emplace_back(i + 'a' - 1);
    for (int i = 1; i < 27; i++)
        if (p(i) == i)
            ans += v[i].size() - 1;
    cout << ans << '\n';
    for (int i = 1; i < 27; i++)
        if (p(i) == i) {
            n = v[i].size();
            for (int j = 1; j < n; j++)
                cout << v[i][j] << ' ' << v[i][j - 1] << '\n';
        }
    return 0;
}

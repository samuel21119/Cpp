/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Mar 23 23:07:25 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int k;
struct node {
    int x, y;
    node(){}
    node(int a, int b) {
        x = a, y = b;
    }
}chip[210], target[210];
vector<char> ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    int mx, my;
    mx = my = 0;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        chip[i] = {a, b};
        mx = max(mx, a);
        my = max(my, b);
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        target[i] = {a, b};
    }
    while (--mx)
        ans.emplace_back('U');
    while (--my)
        ans.emplace_back('L');
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        if (pos == 1) {
            for (int j = 1; j < m; j++)
                ans.emplace_back('R');
            pos = -1;
        }else {
            for (int j = 1; j < m; j++)
                ans.emplace_back('L');
            pos = 1;
        }
        if (i < n)
            ans.emplace_back('D');
    }
    cout << ans.size() << '\n';
    for (char a : ans)
        cout << a;
    return 0;
}

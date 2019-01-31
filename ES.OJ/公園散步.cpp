/*************************************************************************
  > File Name: 公園散步.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue May 22 16:44:20 2018
*************************************************************************/

#include <bits/stdc++.h>
#define maxn 100002
using namespace std;
vector<int> line[maxn];
int ans[maxn], dp[maxn];
int n;
void dfs(int index) {
    if (dp[index] != -1)
        return;
    for (int i : line[index]) {
        dp[i] = dp[index] + 1;
        dfs(i);
    }
}
void dfs2(int index, int dir) {

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp1, tmp2;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> tmp1 >> tmp2;
        line[tmp1].push_back(tmp2);
        line[tmp2].push_back(tmp1);
    }
    cin >> tmp1;
    for (int i = 1; i < n; i++) dp[i] = -1;
    dp[0] = 0;
    dfs(0);
    while (tmp1--) {
        cin >> tmp2;
        cout << ans[tmp2] << '\n';
    }
    return 0;
}

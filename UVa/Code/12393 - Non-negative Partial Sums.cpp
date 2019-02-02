/*************************************************************************
  > File Name: 12393 - Non-negative Partial Sums.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Feb  2 10:44:23 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, ans;
int in[1000010], sum[2000010];
deque<int> que;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> in[i];
            sum[i] = sum[i - 1] + in[i];
        }
        for (int i = n + 1; i < n * 2; i++)
            sum[i] = sum[i - 1] + in[i - n];
        que.clear();
        for (int i = 1; i <= n; i++) {
            while (!que.empty() && sum[que.back()] >= sum[i])
                que.pop_back();
            que.emplace_back(i);
        }
        ans = sum[que.front()] >= 0;
        for (int i = n + 1; i < n * 2; i++) {
            while (!que.empty() && que.front() + n <= i)
                que.pop_front();
            while (!que.empty() && sum[que.back()] >= sum[i])
                que.pop_back();
            que.emplace_back(i);
            if (sum[que.front()] >= sum[i - n])
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}

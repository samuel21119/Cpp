/*************************************************************************
  > File Name: 01169 - Robotruck.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Dec 11 09:03:53 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t, n, C, dp[100010];
int l, r, dq[100010];
int dist[100010], xy[100010], x[100010], y[100010], w[100010];
inline int f(int j) {
	return dp[j] + xy[j + 1] - dist[j + 1];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> C >> n;
		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i] >> w[i];
			dist[i] = dist[i - 1] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
			xy[i] = x[i] + y[i];
			w[i] += w[i - 1];
		}
		// dp[i] = dp[j - 1] + xy[j] + dist[i] - dist[j] + xy[i];
		// dp[i] = (dp[j - 1] + xy[j] - dist[j]) + dist[i] + xy[i];
		l = 0;
		r = 1;
		for (int i = 1; i <= n; i++) {
			while (l != r && C < w[i] - w[dq[l]])
				l++;
			dp[i] = f(dq[l]) + dist[i] + xy[i];
			while (l != r && f(i) <= f(dq[r - 1]))
                r--;
			dq[r++] = i;
		}
		cout << dp[n] << '\n';
		if (t)
			cout << '\n';
	}
	return 0;
}

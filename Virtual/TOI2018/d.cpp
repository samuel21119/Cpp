/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 27 16:56:29 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct xy {
	int x, y;
	bool operator < (const xy &b) const {
		return x < b.x;
	}
}in[3001];
int n, x, y, ans;
deque<int> de;
void check(deque<int> de) {
	sort(de.begin(), de.end());
	int cnt = 0;
	int prev = 0;
	for (int i = 0; i < de.size(); ) {
		if (de[i] - de[prev] <= y)
			cnt++, i++;
		else {
			ans = max(ans, cnt);
			cnt--;
			prev++;
		}
	}
	ans = max(ans, cnt);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> y >> x;
    for (int i = 0; i < n; i++)
    	cin >> in[i].x >> in[i].y;
    sort(in, in + n);
    int prev = 0;
    for (int i = 0; i < n; ) {
    	if (in[i].x - in[prev].x <= x)
    		de.emplace_back(in[i++].y);
    	else {
    		check(de);
    		de.pop_front();
    		prev++;
    	}
    }
    check(de);
    cout << ans << '\n';
    return 0;
}
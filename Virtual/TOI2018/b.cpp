/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 27 15:46:44 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int mod, n, ans;
string in;
int s[1030], tmp[1030];
int fac[54];
bool mode;
int cnt[54];
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> mod;
    cin >> in;
    fac[0] = 1;
    for (int i = 1; i < 54; i++)
    	fac[i] = fac[i - 1] * i % mod;
    for (auto i : in)
    	v.emplace_back(int(i));
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    n = in.length();
    for (int i = 0; i < n; i++) {
    	tmp[i] = s[i] = lower_bound(v.begin(), v.end(), int(in[i])) - v.begin();
    	if (cnt[s[i]]++)
    		mode = 1;
    }
    if (!mode)
    	for (int i = 0; i < n; i++) {
	    	ans = (ans + s[i] * fac[n - i - 1] % mod) % mod;
	    	for (int j = i + 1; j < n; j++)
	    		if (s[j] > s[i]) s[j]--;
    	}
    else {
    	sort(s, s + n);
    	while (next_permutation(s, s + n)) {
    		ans++;
    		bool same = 1;
    		for (int i = 0; i < n; i++)
    			same &= (s[i] == tmp[i]);
    		if (same)
    			break;

    	}
    }
    cout << ans % mod << '\n';
    return 0;
}

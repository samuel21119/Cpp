/*************************************************************************
  > File Name: b905.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Aug 31 19:50:04 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s1, s2;
bool s, e;
const ll mul = 9487;
const ll mod = 982660597;
bool solve() {
	if (!s && s1.front() != s2.front())
		return 0;
	if (!e && s1.back() != s2.back())
		return 0;
	ll target, now, minus;
	int j = 0;
	for (int i = 0; i < s1.length(); ) {
		while (i < s1.length() && s1[i] == '*')
			i++;
		if (i >= s1.length())
			break;
		target = now = 0;
		minus = 1;
		int cnt = 0;
		while (i < s1.length() && s1[i] != '*')
			target = (target * mul + s1[i++]) % mod,
			cnt++, minus = minus * mul % mod;
		for (int k = 0; k < cnt; k++)
			now = (now * mul + s2[j++]) % mod;
		while (j < s2.length() && now != target) {
			now = (now * mul % mod + s2[j++]) % mod;
			now = (now + mod - s2[j - cnt - 1] * minus % mod) % mod;
		}
		if (now != target)
			return 0;
	}
	if (!e) {
		j = s2.length() - 1;
		int i;
		for (i = s1.length() - 1; i >= 0 && j >= 0; i--)
			if (s1[i] == '*')
				break;
			else if (s1[i] != s2[j--])
				return 0;
		if (j == -1 && s1[i] != '*')
			return 0;
	}
	return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
 	cin >> c;
 	while (c--) {
 		cin >> s1 >> s2;
 		if (s1.front() == '*')
 			s = 1;
 		else
 			s = 0;
 		if (s1.back() == '*')
 			e = 1;
 		else
 			e = 0;
 		cout << (solve() ? "Yes\n" : "No\n");
 	}
    return 0;
}

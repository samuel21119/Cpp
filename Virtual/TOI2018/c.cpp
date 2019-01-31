/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 27 15:10:20 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll mod = 1000000007;
class matrix {
public:
	ll c[2][2];
	matrix operator* (const matrix &b) const {
		matrix tmp;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				tmp.c[i][j] = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
					tmp.c[i][j] = (tmp.c[i][j] + c[i][k] * b.c[k][j] % mod) % mod;
		return tmp;
	}
};
matrix fast_calc(ll n, ll x1, ll x2) {
	matrix fast;
	fast.c[0][0] = x2; fast.c[0][1] = x1;
	fast.c[1][0] = 1;  fast.c[1][1] = 0;

	matrix ans;
	ans.c[0][0] = ans.c[1][1] = 1;
	ans.c[1][0] = ans.c[1][0] = 0;

	while (n) {
		if (n & 1)
			ans = ans * fast;
		fast = fast * fast;
		n >>= 1;
	}
	return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, a1, a2, x1, x2;
    cin >> a1 >> a2 >> x1 >> x2 >> n;
    matrix ans = fast_calc(n - 1, x1 % mod, x2 % mod);
    cout << (a2 % mod * ans.c[1][0] % mod + a1 % mod * ans.c[1][1] % mod) % mod << '\n';
    return 0;
}

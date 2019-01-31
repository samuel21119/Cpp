/*************************************************************************
  > File Name: 10290 - {sum+=i++} to Reach N.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Oct 12 17:51:52 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> prime;
bool p[10000010];
int cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    prime.emplace_back(3);
    for (int i = 5; i <= 10000000; i += 2)
        if (!p[i]) {
            prime.emplace_back(i);
            for (int j = i << 1; j <= 10000000; j += i)
                p[j] = 1;
        }
    while (cin >> n) {
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        cnt = 1;
        while (!(n & 1))
            n >>= 1;
        for (ll &i : prime) {
            if (i * i > n)
                break;
            if (n % i)
                continue;
            int tmp = 1;
            while (!(n % i)) {
                tmp++;
                n /= i;
            }
            cnt *= tmp;
        }
        if (n != 1)
            cnt <<= 1;
        cout << cnt << '\n';
    }
    return 0;
}

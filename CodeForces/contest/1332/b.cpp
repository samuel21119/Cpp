/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Mar 31 21:46:32 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int in[1010];
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int p[1010];
int out[1010];
vector<int> prime;
int u[15];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    prime.emplace_back(2);
    for (int i = 3; i < 1000; i += 2) {
        if (p[i])
            continue;
        prime.emplace_back(i);
        for (int j = i * 2; j < 1000; j += i)
            p[j] = 1;
    }
    int t;
    cin >> t;
    while (t--) {
        memset(out, 0, sizeof(out));
        memset(u, 0, sizeof(u));
        cin >> n;
        m = 0;
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }

        vector<int> v;
        for (int i = 0; i < n; i++) {
            int now = in[i];
            int last = -1;
            for (int j = 0; j < (int)prime.size(); j++) {
                if (now % prime[j] == 0) {
                    last = j;
                    break;
                }
            }
            if (u[last] == 0)
                u[last] = ++m;
            out[i] = u[last];
        }
        cout << m << '\n';
        for (int i = 0; i < n; i++) {
            cout << out[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

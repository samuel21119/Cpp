/*************************************************************************
  > File Name: 00686 - Goldbach’s Conjecture (II).cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jun  3 18:30:45 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bool p[32768];
vector<int> prime;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int in;
    for (int i = 2; i < 32768; i++) {
        if (p[i])
            continue;
        for (int j = i << 1; j < 32768; j += i)
            p[j] = 1;
        prime.push_back(i);
    }
    while (cin >> in && in) {
        int up = lower_bound(prime.begin(), prime.end(), in) - prime.begin();
        int cnt, down;
        cnt = down = 0;
        while (1) {
            down = lower_bound(prime.begin(), prime.end(), in - prime[up]) - prime.begin();
            if (down > up)
                break;
            if (prime[down] == in - prime[up])
                cnt++;
            up--;
        }
        cout << cnt << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: 10015 - Josephs Cousin.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:37:12 2017
*************************************************************************/

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
unsigned int prime[3505];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(prime, -1, sizeof(prime));
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    for (int j = 11, c = 4, sq; c < 3505; j += 2) {
        sq = sqrt(j);
        for (int i = 1; prime[i] <= (unsigned)sq; i++)
            if (!(j % prime[i]))
                goto C;
        prime[c++] = j;
        C:;
    }
    int a, b, now;
    while (cin >> a && a) {
        vector<int> v;
        for (int i = 1; i <= a; i++)
            v.push_back(i);
        now = 0;
        b = 0;
        while(v.size() > 1) {
            now += prime[b++] - 1;
            now %= v.size();
            v.erase(v.begin() + now);
        }
        cout << v[0] << '\n';
    }
    return 0;
}


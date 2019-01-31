/*************************************************************************
  > File Name: 13148 - A Giveaway.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Oct  2 22:58:48 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> square, cube;
ll in, tmp;
inline void check(ll i) {
    bool s, c;
    s = c = 0;
    if (*lower_bound(square.begin(), square.end(), i) == i)
        s = 1;
    if (*lower_bound(cube.begin(), cube.end(), i) == i)
        c = 1;
    cout << (s && c ? "Special\n" : "Ordinary\n");
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i * i <= 100000000; i++)
        square.emplace_back(i * i);
    for (int i = 1; i * i * i <= 100000000; i++)
        cube.emplace_back(i * i * i);
    while (cin >> in && in)
        check(in);
    return 0;
}

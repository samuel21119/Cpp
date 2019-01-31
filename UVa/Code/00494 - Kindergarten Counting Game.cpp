/*************************************************************************
  > File Name: 00494 - Kindergarten Counting Game.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Sep  5 20:50:11 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
inline bool isalpha(char i) {
    if ('a' <= i && i <= 'z')
        return 1;
    if ('A' <= i && i <= 'Z')
        return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int cnt;
    bool add;
    while (getline(cin, s)) {
        cnt = add = 0;
        for (auto i : s) {
            if (isalpha(i))
                add = 1;
            else
                cnt += add, add = 0;
        }
        cout << cnt + add << '\n';
    }
    return 0;
}

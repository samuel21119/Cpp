/*************************************************************************
  > File Name: 01585 - Score.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jul 25 22:52:41 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int score, prev, c;
    string s;
    cin >> c;
    while (c--) {
        cin >> s;
        score = prev = 0;
        for (char i : s) {
            if (i == 'O')
                prev++;
            else
                prev = 0;
            score += prev;
        }
        cout << score << '\n';
    }
    return 0;
}

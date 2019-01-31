/*************************************************************************
  > File Name: 00489 - Hangman Judge.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jul 25 21:18:05 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int c, diff;
bool use[26];
bool guess[26];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> c && c != -1) {
        string s;
        cin >> s;
        memset(use, 0, sizeof(use));
        memset(guess, 0, sizeof(guess));
        diff = 0;
        for (unsigned i = 0; i < s.length(); i++)
            use[s[i] - 'a'] = 1;
        for (int i = 0; i < 26; i++)
            diff += use[i];
        cin >> s;
        cout << "Round " << c << '\n';
        c = 7;
        for (unsigned i = 0; i < s.length(); i++) {
            int now = s[i] - 'a';
            if (!use[now]) {
                if (!guess[now])
                    guess[now] = 1, c--;
            }else {
                if (!guess[now])
                    diff--;
                guess[now] = 1;
            }
            if (!c) {
                cout << "You lose.\n";
                break;
            }
            if (!diff) {
                cout << "You win.\n";
                break;
            }
        }
        if (c && diff)
            cout << "You chickened out.\n";
    }
    return 0;
}

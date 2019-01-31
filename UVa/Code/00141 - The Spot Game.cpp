/*************************************************************************
  > File Name: 00141 - The Spot Game.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Oct  5 19:35:11 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool board[50][50], spin[50][50];
int n, a, b, ans;
char c;
inline void rotate() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            spin[j][n - i - 1] = board[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = spin[i][j];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        map<string, bool> m;
        ans = 0;
        memset(board, 0, sizeof(board));
        for (int i = 0; i < (n << 1); i++) {
            cin >> a >> b >> c;
            board[--a][--b] = c == '+';
            string s[4];
            for (int k = 0; k < 4 && !ans; k++) {
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        s[k] += board[i][j] + '0';
                rotate();
            }
            if (m[s[0]] && !ans)
                ans = 1;
            for (int i = 0; i < 4 && !ans; i++)
                m[s[i]] = 1;
            if (ans == 1) {
                ans = 2;
                cout << "Player " << !(i & 1) + 1 << " wins on move " << i + 1 << '\n';
            }
        }
        if (!ans)
            cout << "Draw\n";
    }
    return 0;
}

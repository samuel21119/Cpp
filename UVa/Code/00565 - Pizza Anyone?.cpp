/*************************************************************************
  > File Name: 565 - Pizza Anyone?.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Jul 12 15:01:15 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
short ppl[12][16];
int friendc;
bool choose[16], skip[16];
bool check() {
    for (int i = 0; i < friendc; i++) {
        bool flag = 0;
        for (int j = 0; j < 16; j++) {
            if (ppl[i][j]) {
                if (ppl[i][j] == 1)
                    flag |= choose[j];
                else
                    flag |= !choose[j];
                if (flag)
                    break;
            }
        }
        if (!flag)
            return 0;
    }
    return 1;
}
bool dfs(int index) {
    if (index == 16) {
        if (check()) {
            cout << "Toppings: ";
            for (int i = 0; i < 16; i++)
                if (choose[i])
                    cout << (char)(i + 'A');
            return 1;
        }
        return 0;
    }
    choose[index] = 1;
    if (skip[index])
        return dfs(index + 1);
    if (dfs(index + 1))
        return 1;
    choose[index] = 0;
    if (dfs(index + 1))
        return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string in;
    while (cin >> in) {
        memset(ppl, 0, sizeof(ppl));
        memset(skip, 1, sizeof(skip));
        friendc = 0;
        do {
            for (int i = 0; in[i] != ';'; i += 2) {
                ppl[friendc][in[i + 1] - 'A'] = (in[i] == '+' ? 1 : 2);
                skip[in[i + 1] - 'A'] = 0;
            }
            friendc++;
        }while (cin >> in && in != ".");
        if (!dfs(0))
            cout << "No pizza can satisfy these requests.";
        cout << '\n';
    }
    return 0;
}

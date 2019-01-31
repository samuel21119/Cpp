/*************************************************************************
  > File Name: 00845 - Gas Station Numbers.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri 09 Nov 2018 05:55:33 PM PST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int cnt[10], len;
char s[40], out[40];
inline void change(int i, int mode) {
    if (i == 6 || i == 9) {
        cnt[6] += mode;
        cnt[9] += mode;
    }else if (i == 2 || i == 5) {
        cnt[2] += mode;
        cnt[5] += mode;
    }else
        cnt[i] += mode;
}
bool dfs(int index, bool bigger) {
    if (index == len) {
        if (bigger)
            return 1;
        if (out[len - 1] > s[len - 1])
            return 1;
        return 0;
    }
    if (s[index] == '.')
        index++;
    for (int choose = bigger ? 0 : s[index] - '0'; choose < 10; choose++) {
        if (!cnt[choose])
            continue;
        change(choose, -1);
        out[index] = choose + '0';
        if (dfs(index + 1, bigger || out[index] > s[index]))
            return 1;
        change(choose, 1);
    }
    return 0;
}
int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    while (cin >> s) {
        if (s[0] == '.')
            break;
        memset(out, 0, sizeof(out));
        memset(cnt, 0, sizeof(cnt));
        len = strlen(s);
        for (int i = 0; i < len - 2; i++)
            change(s[i] - '0', 1);
        change(s[len - 1] - '0', 1);
        out[len - 2] = '.';
        if (dfs(0, 0))
            cout << out;
        else
            cout << "The price cannot be raised.";
        cout << '\n';
    }
    return 0;
}

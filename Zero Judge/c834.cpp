/*************************************************************************
  > File Name: c834.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri 09 Nov 2018 07:26:50 AM PST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
char s1[1000010], s2[1000010];
char out[1000010];
int cnt[10], len;
struct node {
    int index, choose;
    bool bigger;
    node(int i, int c, bool b) {
        index = i;
        choose = c;
        bigger = b;
    }
};
bool dfs() {
    stack<node> s;
    int index, choose;
    bool bigger;
    s.push({0, 0, 0});
    while (!s.empty()) {
        node cur = s.top();
        s.pop();
        index = cur.index;
        choose = cur.choose;
        bigger = cur.bigger;
        if (choose > 0)
            cnt[choose]++;
        if (index == len) {
            if (bigger)
                return 1;
            if (out[len - 1] > s2[len - 1])
                return 1;
            continue;
        }
        if (!choose)
            choose = bigger ? 1 : s2[index] - '0';
        else
            choose++;
        while (!cnt[choose] && choose < 10)
            choose++;
        if (choose >= 10) {
            continue;
        }
        cnt[choose]--;
        out[index] = choose + '0';
        s.push({index, choose, bigger});
        s.push({index + 1, 0, bigger || choose > s2[index] - '0'});
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    len = strlen(s1);
    for (int i = 0; i < len; i++)
        cnt[s1[i] - '0']++;
    if (dfs())
        cout << out;
    else
        cout << "QQ";
    cout << '\n';
    return 0;
}

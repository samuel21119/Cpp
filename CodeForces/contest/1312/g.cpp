/*************************************************************************
  > File Name: g.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Mar 13 11:50:21 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, q;
struct trie {
    int id;
    trie* s[26];
    int deep;
    int ans;
    bool check;
    trie(){
        check = ans = id = deep = 0;
        fill(s, s + 26, nullptr);
    }
    trie(int a, int b) {
        ans = deep = a;
        check = 0;
        id = b;
        fill(s, s + 26, nullptr);
    }
};
trie *in[1000010];
int dfs(trie* now, trie* parent, int have) {
    int add = 0;
    if (parent->deep + 1 == now->deep)
        now->ans = parent->ans + 1;
    else {
        now->ans = parent->ans + min(now->deep - parent->deep, have);
        if (now->deep - parent->deep >= 2)
            now->ans = min(now->ans, parent->ans + 2);
    }
    cout << now->id << "<-" << parent->id << ' ' << now->ans << ' ' << have << ' ' << endl;
    if (now->check)
        parent = now;
    add += now->check;
    for (int i = 0; i < 26; i++)
        if (now->s[i] != nullptr) {
            int t = dfs(now->s[i], parent, have + add);
            add += t;
        }
    return add;
}
int c[1000000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    in[0] = new trie();
    for (int i = 1; i <= n; i++) {
        int a;
        char b;
        cin >> a >> b;
        in[i] = new trie(in[a]->deep + 1, i);
        in[a]->s[b - 'a'] = in[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> c[i];
        in[c[i]]->check = 1;
    }
    dfs(in[0], in[0], 0);
    for (int i = 0; i < q; i++)
        cout << in[c[i]]->ans << ' ';
    return 0;
}

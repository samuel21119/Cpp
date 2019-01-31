/*************************************************************************
  > File Name: 10503 - The Dominoes Solitaire.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:57:57 2017
*************************************************************************/

#include <iostream>
#include <utility>
#include <vector>
#define F first
#define S second
#define P push_back
using namespace std;
pair<int, int> in[16];
bool use[16];
vector<pair<int, int> > r[100]; 
int n, m, s[2], e[2];
void swap(pair<int, int> &in) {
    int a = in.S;
    in.S = in.F;
    in.F = a;
}
bool dfs(int so, int c) {
    if (c == n) {
        if (in[so].S == e[0])
            return true;
        else
            return false;
    }
    int S = in[so].S;
    int len = r[S].size();
    bool re = false;
    for (int i = 0; i < len; i++) {
        if (use[r[S][i].F]) continue;
        use[r[S][i].F] = 1;
        if (r[S][i].S) {
            swap(in[r[S][i].F]);
            re |= dfs(r[S][i].F, c + 1);
            swap(in[r[S][i].F]);
        }
        else
            re |= dfs(r[S][i].F, c + 1);
        use[r[S][i].F] = 0;
    }
    return re;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int, int> a;
    while (cin >> n && n) {
        cin >> m >> s[0] >> s[1] >> e[0] >> e[1];
        for (int i = 0; i < m; i++) {
            cin >> in[i].F >> in[i].S;
            a.F = i; a.S = 0;
            r[in[i].F].P(a);
            a.S = 1;
            r[in[i].S].P(a);
        }
        int len = r[s[1]].size();
        bool ans = false;
        for (int i = 0; i < len; i++) {
            use[r[s[1]][i].F] = 1;
            if (r[s[1]][i].S) {
                swap(in[r[s[1]][i].F]);
                ans |= dfs(r[s[1]][i].F, 1);
                swap(in[r[s[1]][i].F]);
            }else
                ans |= dfs(r[s[1]][i].F, 1);
            use[r[s[1]][i].F] = 0;
        }
        for (int i = 0; i < 100; i++) r[i].clear(); 
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}


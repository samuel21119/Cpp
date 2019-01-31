/*************************************************************************
  > File Name: b417.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Oct 29 21:53:22 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
struct MO {
    int l, r, id, l_id, r_id;
    MO(int l, int r, int i, int li, int ri) : l(l), r(r), id(i), l_id(li), r_id(ri) {}
    MO() {}
    bool operator< (const MO &b) const {
        if (l_id != b.l_id)
            return l_id < b.l_id;
        return r_id < b.r_id;
    }
};
int ans, n, m, a, b, block;
int val_cnt[100010], cnt[100010];
//  數字i出現次數    出現次數為i有幾個
int input[100010];
inline void addnum(int i) {
    cnt[val_cnt[i]]--;
    cnt[++val_cnt[i]]++;
    if (cnt[ans + 1])
        ans++;
}
inline void delnum(int i) {
    cnt[val_cnt[i]]--;
    cnt[--val_cnt[i]]++;
    if (!cnt[ans])
        ans--;
}
MO query[1000010];
pair<int, int> out[1000010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    block = sqrt(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        query[i] = {--a, --b, i, a / block, b / block};
    }
    sort(query, query + m);
    int l = 0, r = -1;
    for (int i = 0; i < m; i++) {
        MO &now = query[i];
        while (r < now.r)
            addnum(input[++r]);
        while (l > now.l)
            addnum(input[--l]);
        while (r > now.r)
            delnum(input[r--]);
        while (l < now.l)
            delnum(input[l++]);
        out[now.id] = {ans, cnt[ans]};
    }
    for (int i = 0; i < m; i++)
        cout << out[i].first << ' ' << out[i].second << '\n';
    return 0;
}

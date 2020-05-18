/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Apr 23 23:11:07 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> in[100010];
int cnt[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        multiset<int> s;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> in[i].first;
            in[i].second = i + 1;
            cnt[i + 1] = 1;
            s.insert(1);
        }
        sort(in, in + n);
        bool ans = 1;
        int b = n;
        for (int i = 0; i < n; i++) {
            int num = i + 1;
            int pos = in[i].second;
            num = pos;
            if (cnt[pos] < *s.rbegin()) {
                //cout << i << endl;
                ans = 0;
                break;
            }
            s.erase(s.find(cnt[num]));
            if (pos == b) {
                b--;
            }else {
                if (cnt[num + 1] != -1) {
                    s.erase(s.find(cnt[num + 1]));
                    cnt[num + 1] += cnt[num];
                    s.insert(cnt[num + 1]);
                }
            }
            cnt[num] = -1;

        }
        cout << (ans ? "Yes" : "No") << '\n';
    }
    return 0;
}

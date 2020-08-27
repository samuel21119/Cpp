/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Aug 27 14:03:27 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[100010];
int cnt2;
int cnt4;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        if (cnt[a] % 2 == 0)
            cnt2++;
        if (cnt[a] % 4 == 0)
            cnt4++;
    }
    cin >> n;
    while (n--) {
        int a;
        char m;
        cin >> m;
        cin >> a;
        if (m == '-') {
            cnt[a]--;
            if (cnt[a] % 2 == 1)
                cnt2--;
            if (cnt[a] % 4 == 3)
                cnt4--;
        }else {
            cnt[a]++;
            if (cnt[a] % 2 == 0)
                cnt2++;
            if (cnt[a] % 4 == 0)
                cnt4++;
        }
        cout << (cnt4 && cnt2 - 2 >= 2 ? "YES" : "NO") << '\n';
    }
    return 0;
}

/*************************************************************************
  > File Name: a.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Oct 25 22:30:49 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int cnt[30];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            memset(cnt, 0, sizeof(cnt));
            int m = 0;
            for (int k = i; k <= j; k++)
                m = max(m, ++cnt[s[k] - 'a']);
            if (m * 2 <= (j - i + 1)) {
                cout << "YES\n";
                for (int k = i; k <= j; k++)
                    cout << s[k];
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}

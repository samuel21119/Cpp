/*************************************************************************
  > File Name: 00872 - Ordering.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Dec 18 12:10:06 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
bool m[26][26], ans, use[26];
char out[26], a, b, c;
string s, in;
void dfs(int index) {
    if (index == n) {
        ans = 1;
        cout << out[0];
        for (int i = 1; i < n; i++)
            cout << ' ' << out[i];
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (use[i])
            continue;
        for (int j = 0; j < index; j++)
            if (m[s[i] - 'A'][out[j] - 'A'])
                return;
        use[i] = 1;
        out[index] = s[i];
        dfs(index + 1);
        use[i] = 0;
    }  
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        ans = 0;
        memset(m, 0, sizeof(m));
        cin.ignore();
        getline(cin, in); {
            stringstream ss(in);
            s.clear();
            while (ss >> a)
                s += a;
        }
        getline(cin, in); {
            stringstream ss(in);
            while (ss >> a >> b >> c) {
                m[a - 'A'][c - 'A'] = 1;
                if (m[c - 'A'][a - 'A'])
                    ans = 1;
            }
        }
        if (ans) {
            cout << "NO\n";
            if (t)
                cout << '\n';
            continue;
        }
        sort(s.begin(), s.end());
        n = s.length();
        dfs(0);
        if (!ans)
            cout << "NO\n";
        if (t)
            cout << '\n';
    }
    return 0;
}

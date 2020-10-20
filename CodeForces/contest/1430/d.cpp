/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 14 20:51:19 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
bool popped[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <= n; i++)
            popped[i] = 0;
        cin >> s;
        int last = 0, cnt = 0, i = 0;
        int remain = n;
        while (i < n && remain) {
            while (last < n - 1 && s[last] != s[last + 1])
                last++;
            if (last != n - 1)
                popped[last++] = 1;
            else {
                while (i < n && popped[i])
                    i++;
                popped[i] = 1;
            }

            remain--;

            while (popped[i])
                i++;
            cout << i << endl;
            int j = i;
            char cur = s[i];
            while (j < n && (popped[j] || s[j] == cur))
                remain -= !popped[j], popped[j++] = 1;
            last = max(last, j);
            i = j;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}

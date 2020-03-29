/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Mar 23 22:48:06 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> lists[100010];
int choosed[100010];
int used[100010];
int ptr;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ptr++;
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            lists[i].clear();
            int k;
            cin >> k;
            bool c = 0;
            while (k--) {
                int a;
                cin >> a;
                a--;
                lists[i].emplace_back(a);
                if (!c) {
                    if (used[a] != ptr) {
                        used[a] = ptr;
                        choosed[i] = ptr;
                        cnt++;
                        c = 1;
                    }
                }
            }
        }
        if (cnt == n) {
            cout << "OPTIMAL";
        }else {
            int a, b;
            for (a = 0; a < n; a++) {
                if (choosed[a] != ptr)
                    break;
            }
            for (b = 0; b < n; b++)
                if (used[b] != ptr)
                    break;
            if (a == n || b == n) {
                cout << "OPTIMAL";
            }else 
                cout << "IMPROVE" << '\n' << a + 1 << ' ' << b + 1;
        }
        cout << '\n';
    }
    return 0;
}

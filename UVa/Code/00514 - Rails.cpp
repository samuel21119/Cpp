/*************************************************************************
  > File Name: 00514 - Rails.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jun  3 18:13:19 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, test, t[1001];
    int c = 0;
    while (cin >> n) {
        if (c)
            cout << '\n';
        else
            c = 1;
        if (!n)
            break;
        while (cin >> test && test) {
            stack<int> B;
            bool flag = true;
            t[0] = test;
            for (int i = 1; i < n; i++)
                cin >> t[i];
            int j = 0;
            for (int i = 0; i < n; i++) {
                if (t[i] > j)
                    while (t[i] > j)
                        B.push(++j);
                else if (B.top() != t[i]) {
                    flag = false;
                    break;
                }
                B.pop();
            }
            cout << (flag ? "Yes\n" : "No\n");
        }
    }
    return 0;
}

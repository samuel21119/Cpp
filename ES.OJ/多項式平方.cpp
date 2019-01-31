/*************************************************************************
  > File Name: 多項式平方.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat May 19 08:06:44 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        bool flag = 1;
        long long a = 0, tmp;
        cin >> n;
        for (int i = 0; i < n + 1; i++) {
            cin >> tmp;
            a += tmp;
        }
        a *= a;
        for (int i = 0; i < n * 2 + 1; i++) {
            cin >> tmp;
            a -= tmp;
            if (a < 0)
                flag = 0;
        }
        if (a > 0)
            flag = 0;
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}

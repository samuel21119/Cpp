/*************************************************************************
  > File Name: 12325 Zombies Treasure Chest.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Oct  1 22:20:00 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long n, s1, v1, s2, v2, ans;
int i, c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (cin >> c; i < c; ) {
        cin >> n >> s1 >> v1 >> s2 >> v2;
        ans = 0;
        if (v1 * s2 >= v2 * s1) {
            if(n / s1 > s1)
                for(int i = 0; i < s1; i++)
                    ans = max(ans, i * v2 + (n - i * s2) / s1 * v1);
            else
                for(int i = 0; i <= n / s1; i++)
                    ans = max(ans, i * v1 + (n - i * s1) / s2 * v2);
        }
        else {
            if(n / s2 > s2)
                for(int i = 0; i < s2; i++)
                    ans = max(ans, i * v1 + (n - i * s1) / s2 * v2);
            else
                for(int i = 0; i <= n / s2; i++)
                    ans = max(ans, i * v2 + (n - i * s2) / s1 * v1);
        }
        cout << "Case #" << ++i << ": " << ans << '\n';
    }
    return 0;
}

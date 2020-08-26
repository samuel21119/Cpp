/*************************************************************************
  > File Name: b.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Aug 24 13:04:10 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;
string s[110];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
 
        for(int i = 0; i < n; ++i)
            cin >> s[i];
    
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
            ans += s[i][m - 1] != 'D';
 
        for(int i = 0; i < m - 1; i++)
            ans += s[n - 1][i] != 'R';
 
        cout << ans << "\n";
    }
    return 0;
}

/*************************************************************************
  > File Name: 12582 - Wedding of Sultan.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:36:53 2017
*************************************************************************/

#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
using namespace std;
int ans[26];
int main() {
    int _case;
    cin >> _case;
    for (int c = 1; c <= _case; c++) {
        char s[102];
        cin >> s;
        memset(ans, 0, sizeof(ans));
        stack<int> sta;
        ans[s[0]-'A']--;
        int a;
        for (int i = 0; i < (int)strlen(s); i++) {
            a = s[i] - 'A';
            if (sta.empty()) { sta.push(a); continue;}
            ans[sta.top()]++;
            if (sta.top() == a) { sta.pop(); continue;}
            sta.push(a);
        }
        cout << "Case "<< c << '\n';
        for (int i = 0; i < 26; i++)
            if (ans[i])
                cout << (char)(i + 'A') << " = " << ans[i] << '\n';
    }
    return 0;
}


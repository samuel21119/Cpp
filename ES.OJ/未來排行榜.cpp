/*************************************************************************
  > File Name: 未來排行榜.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Feb  1 12:36:07 2018
*************************************************************************/

#include <iostream>
using namespace std;
char input[200005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, len;
    cin >> c;
    while (c--) {
        cin >> len;
        bool ans = true;
        for (int i = 0; i < len; i++) cin >> input[i];
        for (int i = 0; i < len && ans; i++)
            if (input[i] == '<') ans = false;
            else if (input[i] == '>') break;
        for (int i = len - 1; i >= 0 && ans; i--)
            if (input[i] == '>') ans = false;
            else if (input[i] == '<') break;
        if (ans) cout << "Yes\n";
        else     cout << "No\n";
    }
    return 0;
}

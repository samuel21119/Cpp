/*************************************************************************
  > File Name: 10063 - Knuths Permutation.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:48:12 2017
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
string s;
char ans[11], len;
void dfs(int index) {
    if (index == len) {
        ans[index] = '\0';
        cout << ans << '\n';
        return;
    }
    for (int i = index; i > 0; i--)
        ans[i] = ans[i - 1];
    for (int i = 0; i <= index; i++) {
        ans[i] = s[index];
        dfs(index+1);
        ans[i] = ans[i + 1];
    }
}
int main() {
    len = -1;
    while (cin >> s) {
        if (len != -1)
            cout << '\n';
        len = s.length();
        dfs(0);
    }
    return 0;
}


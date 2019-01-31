/*************************************************************************
  > File Name: 11584 - Partitioning by Palindromes.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:33:45 2017
*************************************************************************/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
char a[1000];
int len;
bool ifP(int i, int j) {
    while (i < j)
        if (a[i] != a[j])
            return false;
        else
            i++, j--;
    return true;
}
int main() {
    int c;
    int ans[1000];
    cin >> c;
    while (c--) {
        cin >> (a+1);
        len = strlen(a+1);
        ans[0] = 0;
        for (int i = 1; i <= len; i++) {
            ans[i] = i + 1;
            for (int j = 1; j <= i; j++)
                if (ifP(j, i)) {
                    ans[i] = min(ans[i], ans[j - 1] + 1);
                }
        }
        cout << ans[len] << '\n';
    }
    return 0;
}


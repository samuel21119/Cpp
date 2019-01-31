/*************************************************************************
  > File Name: B.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jun  1 22:57:43 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n;
string input[101];
bool ans = true;
bool cmp(string a, string b) {
    if (a.length() < b.length())
        return 1;
    if (a.length() > b.length())
        return 0;
    if (a == b)
        return 0;
    ans = false;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    sort(input, input + n, cmp);
    if (!ans) {
        cout << "NO\n";
        return 0;
    }
    n--;
    for (int i = 0; i < n; i++) {
        bool flag = 0;
        int lenb = input[i + 1].length();
        for (int b = 0; b < lenb && !flag; b++) {
            int a;
            for (a = 0; a < input[i].length(); a++)
                if (input[i + 1][b + a] != input[i][a] || a + b == lenb) {
                    a = -1;
                    break;
                }
            if (a > 0)
                flag = 1;
        }
        if (!flag) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    n++;
    for (int i = 0; i < n; i++)
        cout << input[i] << '\n';
    return 0;
}

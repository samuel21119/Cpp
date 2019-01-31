/*************************************************************************
  > File Name: 10106 - Product.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec  1 22:32:22 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

char s1[260], s2[260];
int out[600];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> s1 >> s2) {
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        int len = l1 + l2 - 1;
        memset(out, 0, sizeof(out));
        reverse(s1, s1 + l1);
        reverse(s2, s2 + l2);
        for (int i = 0; i < l1; i++)
            for (int j = 0; j < l2; j++)
                out[i + j] += (s1[i] - '0') * (s2[j] - '0');
        for (int i = 0; i < len; i++)
            if (out[i] > 9) {
                out[i + 1] += out[i] / 10;
                out[i] %= 10;
                if (i == len - 1)
                    len++;
            }
        reverse(out, out + len);
        int start = 0;
        while (!out[start] && start < len)
            start++;
        for (int i = start; i < len; i++)
            cout << out[i];
        if (start == len)
            cout << 0;
        cout << '\n';
    }
    return 0;
}

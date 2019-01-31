/*************************************************************************
  > File Name: 字串加密.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon May 14 23:40:20 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

char input[200005], A[10000005], B[10000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int conv[256];
    cin >> n >> m;
    cin >> input >> A >> B; 
    for (int i = 48; i < 130; i++)
        conv[i] = i;
    for (int i = 0; i < m; i++) {
        for (int j = '0'; j <= '9'; j++)
            if (conv[j] == A[i])
                conv[j] = B[i];
        for (int j = 'A'; j <= 'Z'; j++)
            if (conv[j] == A[i])
                conv[j] = B[i];
        for (int j = 'a'; j <= 'z'; j++)
            if (conv[j] == A[i])
                conv[j] = B[i];
    }
    for (int i = 0; i < n; i++)
        cout << (char)conv[input[i]];
    cout << '\n';
    return 0;
}

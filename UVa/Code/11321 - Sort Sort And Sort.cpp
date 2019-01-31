/*************************************************************************
  > File Name: 11321 - Sort Sort And Sort.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Jun  1 21:33:43 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int M;
bool cmp (int a, int b) {
    if (a % M > b % M)
        return 0;
    if (a % M < b % M)
        return 1;
    int aa = a & 1;
    int bb = b & 1;
    if (aa ^ bb) {
        if (bb)
            return 0;
        return 1;
    }
    if (aa & bb)
        return a > b;
    return a < b;
}
int input[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n >> M && n && M) {
        for (int i = 0; i < n; i++) cin >> input[i];
        sort(input, input + n, cmp);
        cout << n << " " << M << '\n';
        for (int i = 0; i < n; i++) cout << input[i] << '\n';
    }
    cout << "0 0\n";
    return 0;
}

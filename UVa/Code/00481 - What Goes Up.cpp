/*************************************************************************
  > File Name: 481 - What Goes Up.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed 16 May 2018 03:36:31 PM CST
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input, lis, out, print;
    int in;
    while (cin >> in) {
        input.push_back(in);
        out.push_back(0);
    }
    int len = input.size();
    int ans, tmp;
    ans = 1;
    lis.push_back(input[0]);
    for (int i = 1; i < len; i++) {
        int n = input[i];
        if (n > lis.back()) {
            lis.push_back(n);
            out[i] = ans++;
        }
        else {
            int lower = lower_bound(lis.begin(), lis.end(), n) - lis.begin();
            lis[lower] = n;
            out[i] = lower;
        }
    }
    cout << ans << "\n-\n";
    tmp = ans - 1;
    for (int i = len - 1; i >= 0; i--) {
        if (tmp == out[i]) {
            print.push_back(i);
            tmp--;
        }
    }
    for (int i = ans - 1; i >= 0; i--)
        cout << input[print[i]] << '\n';
    return 0;
}

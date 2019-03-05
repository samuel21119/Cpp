
/*************************************************************************
  > File Name: 10157 - Expressions.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Mar  1 23:04:42 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;


struct bigint {
    int num[100] = {0};
    int len = 1;
    bigint operator+ (const bigint &b) const {
        int mx = max(len, b.len);
        bigint re;
        re.len = mx;
        for (int i = 0; i < mx; i++) {
            if (i < len)
                re.num[i] += num[i];
            if (i < b.len)
                re.num[i] += b.num[i];
        }
        for (int i = 0; i < len; i++) {
            if (re.num[i] > 9) {
                re.num[i] -= 10;
                re.num[i + 1]++;
            }
        }
        if (re.num[mx] > 0)
            re.len++;
        return re;
    }
    bigint operator- (const bigint &b) {
        bigint re;
        re.len = len;
        for (int i = len - 1; i >= 0; i--) {
            re.num[i] = num[i] - b.num[i];
        }
        for (int i = 0; i < len - 1; i++) {
            if (re.num[i] < 0) {
                re.num[i] += 10;
                re.num[i + 1]--;
            }
        }
        while (re.num[re.len - 1] == 0)
            re.len--;
        return re;
    }
    bigint operator* (const bigint &b) {
        bigint re;
        re.len = len + b.len - 1;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < b.len; j++)
                re.num[i + j] += num[i] * b.num[j];
        for (int i = 0; i < re.len; i++) {
            if (re.num[i] > 9) {
                re.num[i + 1] += re.num[i] / 10;
                re.num[i] %= 10;
            }
        }
        if (re.num[re.len] > 0)
            re.len++;
        return re;
    }
};
string out(bigint i) {
    string s;
    while (i.len--)
        s += i.num[i.len] + '0';
    if (s.empty())
        return "0";
    return s;
}
bigint dp[151][151];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 150; i++) {
        dp[0][i].len = 1;
        dp[0][i].num[0] = 1;
    }
    for (int i = 1; i <= 150; i++) {
        for (int j = 1; j <= 150; j++) {
            for (int k = 0; k < i; k++)
                dp[i][j] = dp[i][j] + (dp[k][j - 1] * dp[i - k - 1][j]);
        }
    }
    int n, d;
    while (cin >> n >> d) {
        if (n & 1)
            cout << "0\n";
        else {
            cout << out(dp[n / 2][d] - dp[n / 2][d - 1]) << '\n';;
        }
    }
    return 0;
}

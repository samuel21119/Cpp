/*************************************************************************
  > File Name: 412 - Pi.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Sep 29 10:21:53 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b)
        return gcd(b, a % b);
    return a;
}
int n, in[60], sum;
double pi;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        for (int i = 0; i < n; i++)
            cin >> in[i];
        sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (gcd(in[i], in[j]) == 1)
                    sum++;
        if (sum)
            cout << fixed << setprecision(6) << sqrt(6.0 * double((n * n - n) / 2) / double(sum)) << '\n';
        else
            cout << "No estimate for this data set.\n";
    }
    return 0;
}

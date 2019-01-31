/*************************************************************************
  > File Name: 10107 - What is the Median.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Dec 14 14:31:26 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<long long> arr;
long long n, s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n) {
        if (!s) {
            cout << n;
            arr.emplace_back(n);
            s++;
        }else {
            arr.insert(lower_bound(arr.begin(), arr.end(), n), n);
            s++;
            if (s & 1)
                cout << arr[s / 2];
            else
                cout << (arr[s / 2] + arr[s / 2 - 1]) / 2;
        }
        cout << '\n';
    }
    return 0;
}

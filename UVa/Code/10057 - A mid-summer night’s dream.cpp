/*************************************************************************
  > File Name: 10057 - A mid-summer night’s dream.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Feb  6 16:10:08 2018
*************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int input[1000010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mid_min, numbers, diff;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> input[i];
        sort(input, input + n);
        mid_min = input[n/2];
        if (n & 1) {
            numbers = upper_bound(input, input + n, mid_min) - lower_bound(input, input + n, mid_min);
            cout << mid_min << ' ' << numbers << " 1\n";
            continue;
        }
        mid_min = input[n/2 - 1];
        int mid2 = input[n/2];
        int last = mid_min;
        auto upper = upper_bound(input, input + n, mid2);
        auto lower = lower_bound(input, input + n, mid_min);
        diff = mid2 - mid_min + 1;
        numbers = upper - lower;

        cout << mid_min << ' ' << numbers << ' ' << diff << '\n';
    }
}

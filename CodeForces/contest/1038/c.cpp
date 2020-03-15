/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Sep  6 22:33:07 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll a[100001], b[100001], sum;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int j = n - 1;
    int i = j;
    int t = 0;
    while (!(i == -1 && j == -1)) {
        if (!(t & 1)) {
            if (i < 0)
                j--;
            else if(j < 0)
                sum += a[i--];
            else if (a[i] < b[j])
                j--;
            else if (a[i] == b[j])
                i--, j--, t = 1;
            else
                sum += a[i--];
        }else {
            if (j < 0)
                i--;
            else if (i < 0)
                sum -= b[j--];
            else if (a[i] > b[j])
                i--;
            else if (a[i] == b[j])
                i--, j--, t = 0;
            else
                sum -= b[j--];
        }
        t = !t;
    }
    cout << sum << '\n';
    return 0;
}

/*************************************************************************
  > File Name: 11237 - Halloween treats.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:27:15 2017
*************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int in[100003], sum[100003];
int a, b;
void solve() {
    int mod[100003];
    memset(mod, -1, sizeof(mod));
    mod[0] = sum[0] = 0;
    for (int i = 1; i <= b; i++) {
        sum[i] = (sum[i - 1] + in[i]) % a;
        if (mod[sum[i]] != -1) {
            for (int j = mod[sum[i]] + 1; j < i; j++) {
                cout << j << ' ';
            }
            cout << i << '\n';
            return;
        }
        mod[sum[i]] = i;
    }
}
int main() {
    while (1) {
        cin >> a >> b;
        if (!(a + b))
            break;
        for (int i = 1; i <= b; i++) {
            cin >> in[i];
            in[i] %= a;
        }
        solve();
    }
    return 0;
}


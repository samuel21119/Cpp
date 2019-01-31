/*************************************************************************
  > File Name: 10755 - Garbage Heap.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jan 31 11:09:11 2018
*************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
ll input[21][21][21];
int A, B, C;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        cin >> A >> B >> C;
        memset(input, 0, sizeof(input));
        ll mx = 0x7FFFFFFFFFFFFFFF;
        mx *= -1;
        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++) {
                    cin >> input[i][j][k];
                    mx = max(mx, (ll)input[i][j][k]);
                    input[i][j][k] += input[i][j][k - 1];
                    input[i][j][k] += input[i][j - 1][k];
                    input[i][j][k] -= input[i][j - 1][k - 1];
                }
        if (mx < 0) {
            cout << mx << '\n';
            if (c)
                cout << '\n';
            continue;
        }
        ll ans = 0;
        for (int i1 = 1; i1 <= B; i1++)
            for (int j1 = 1; j1 <= C; j1++)
                for (int i2 = i1; i2 <= B; i2++)\
                    for (int j2 = j1; j2 <= C; j2++) {
                        ll cur = 0;
                        for (int k = 1; k <= A; k++) {
                            ll temp = input[k][i2][j2] - input[k][i2][j1 - 1] - input[k][i1 - 1][j2] + input[k][i1 - 1][j1 - 1];
                            cur = max(0LL, temp + cur);
                            ans = max(ans, cur);
                        }
                    }
        cout << ans << '\n';
        if (c) cout << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int x[300010];
int change[300010];
int n;
int in[300010];
bool v[300010];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        x[in[i]] = i;
        if (v[in[i]]) {
            cout << "-1\n";
            return 0;
        }
        v[in[i]] = 1;
    }
    for (int a = 2; a <= n; a++) {
        int j = in[a];
        int i = in[a - 1];
        int ii = x[i + 1];
        int jj = x[j + 1];
        if (ii < jj )
            change[j] = change[i];
        else
            change[j] = change[i] + 1;
    }
    if (change[in[n]] >= 26) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << char('a' + change[i]);
    }
    cout << '\n';
    return 0;
}
/*
7
7 1 3 6 2 5 4
*/

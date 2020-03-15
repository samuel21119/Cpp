
#include <bits/stdc++.h>
using namespace std;
int a, cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    while (a)
        cnt += 1, a >>= 1;
    cout << cnt << '\n';
    return 0;
}

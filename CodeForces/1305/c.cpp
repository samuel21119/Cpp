#include <bits/stdc++.h>
using namespace std;

int in[200010];
bool cnt[1010];
int main() {
    int n, m;
    int ans = 1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (cnt[a % m]) {
            cout << "0\n";
            return 0;
        }
        cnt[a % m] = 1;
        in[i] = a;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = ans * (abs(in[j] - in[i]) % m) % m;
    cout << ans << '\n';
}
/*

*/

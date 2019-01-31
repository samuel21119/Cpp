#include <bits/stdc++.h>
using namespace std;
long long n, s, ans;

long long in[200010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in, in + n);
    if (in[n / 2] < s) {
        for (int i = n / 2; i < n; i++)
            if (in[i] < s)
                ans += s - in[i];
    }else if (in[n / 2] > s) {
        for (int i = n / 2; in[i] > s && i >= 0; i--)
            ans += in[i] - s;
    }

    cout << ans << '\n';
    return 0;
}

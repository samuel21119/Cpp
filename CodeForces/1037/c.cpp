
#include <bits/stdc++.h>
using namespace std;
char s1[1000010], s2[1000010];
int n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s1[i] == s2[i + 1] && s1[i + 1] == s2[i] && s1[i] != s2[i]) {
            swap(s1[i], s1[i + 1]);
            ans++;
        }
        if (s1[i] != s2[i]){
            ans++;
            s1[i] = s2[i];
        }
    }
    cout << ans << '\n';
    return 0;
}

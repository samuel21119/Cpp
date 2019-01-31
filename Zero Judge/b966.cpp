#include <iostream>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
pair<int, int> in[1000001];
int ans;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, l, r;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> in[i].first >> in[i].second;
        }
        sort(in, in + n);
       ans = 0;
        int s, l;
        s = in[0].first;
        l = in[0].second;
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                ans += l - s;
                break;
            }
            if (l >= in[i + 1].first) {
                l = in[i + 1].second > l ? in[i + 1].second : l;
            }else {
                ans += l - s;
                s = in[i + 1].first;
                l = in[i + 1].second;
            }
        }
        cout << ans << '\n';
    }
}

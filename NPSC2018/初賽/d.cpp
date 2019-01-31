#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
pair<ll, ll> in[5010];
ll k;
ll arr[5010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll ans = 1LL << 60;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> in[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i].second;
    } 
    sort(in, in + n);
    for (int i = 0 ; i < n; i++)
        arr[i] = in[i].first;
    int index = lower_bound(arr, arr + n, k) - arr;
    if (arr[index] == k) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = index; i < n; i++)
        ans = min(ans, in[i].second);
    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            ll s = arr[i] + arr[j];
            if (s < k)
                continue;
            if (s == k) {
                cout << "0\n";
                return 0;
            }
            ans = min(ans, min(in[i].second, in[j].second));
        }
    }
    cout << (ans == (1LL << 60) ? -1 : ans) << '\n';
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll, ll> input[2010];
ll n;
double sum;
ll pow(ll i) {
    return i * i;
}
double len(int i, int j) {
    int x1 = input[i].first;
    int x2 = input[j].first;
    int y1 = input[i].second;
    int y2 = input[j].second;
    return sqrt(pow(x1 - x2) + pow(y1 - y2));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input[i].first >> input[i].second;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            sum += len(i, j) * 6.0 / (n * n - n);
    cout << fixed << setprecision(8) << sum  << '\n';
}
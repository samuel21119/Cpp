#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, MIN, MAX;
    int in[1001];
    cin >> x;
    MIN = 1 << 30;
    MAX = -1;
    for (int i = 0; i < x; i++) {
        cin >> in[i];
        MIN = min(MIN, in[i]);
        MAX = max(MAX, in[i]);
    }
    cout << MAX - MIN - x + 1 << '\n';
}
#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n == 0) {
            cout << "Labrador\n";
            continue;
        }
        int t = (n + k - 1) / k ;
if (t <= 2 || !(t & 1))
    cout << "Kitty\n";
else
    cout << "Labrador\n";
    }
}
/*
int t = n / k;
if (t <= 2 || !(t & 1))
    cout << "Kitty\n";
else
    cout << "Labrador\n";
    */

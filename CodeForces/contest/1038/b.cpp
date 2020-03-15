#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n < 3) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    if(n & 1) {
        cout << n / 2 << ' ';

        for(int i = 2; i <= n; i += 2)
            cout << i << ' ';
        cout << n / 2 + 1 << '\n';
        for(int i = 1; i <= n; i += 2)
            cout << i << ' ';
        cout << '\n' ;
        return 0;
    }
    cout << n / 2 << ' ';
    for(int i = 2; i <= n; i += 2)
        cout << i << ' ';

    cout << '\n' << n / 2 << ' ';
    for(int i = 1; i <= n; i += 2)
        cout << i << ' ';
    cout << '\n' ;

    return 0;
}

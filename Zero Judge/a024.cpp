#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a, b, m;
    while (cin >> a >> b) {
        int c = 1;
        int out;
        m = min(a, b);
        for (; c <= m; c++) {
            if (a % c == 0 && b % c == 0) {
                out = c;
            }
        }
        cout << out << '\n';
    }
}

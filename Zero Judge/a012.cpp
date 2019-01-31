#include <iostream>
#include <cmath>
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    unsigned long long int a, b;
    while(std::cin >> a >> b)
        std::cout << ((a >= b) ? (a - b) : (b - a)) << '\n';
}

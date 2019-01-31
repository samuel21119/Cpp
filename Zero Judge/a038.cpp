#include <iostream>
int main() {
    int a;
    std::cin >> a;
    if (!a)
        std::cout << a;
    bool b = 1;
    while (a > 0) {
        if (!(a % 10) && b) {
            a /= 10; continue;}
        else
            b = 0;
        std::cout << a % 10, a /= 10;
    }
}

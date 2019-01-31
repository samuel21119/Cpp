/*************************************************************************
  > File Name: 10055 - Hashmat the Brave Warrior.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:47:32 2017
*************************************************************************/

#include <iostream>
#include <cmath>
int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    unsigned long long int a, b;
    while(std::cin >> a >> b)
        std::cout << ((a >= b) ? (a - b) : (b - a)) << '\n';
    return 0;
}


/*************************************************************************
  > File Name: 10469 - To Carry or not to Carry.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:57:24 2017
*************************************************************************/

#include <iostream>
int main() {
    int a, b;
    while(std::cin >> a >> b)
        std::cout << (a ^ b) << '\n';
    return 0;
}

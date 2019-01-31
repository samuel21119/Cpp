/*************************************************************************
  > File Name: 10071 - Back to High School Physics.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:50:01 2017
*************************************************************************/

#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    while(cin >> a >> b) {
        if (b == 0)
            a = 0;
        else
            a = a * b * b * 2 / b;
        cout << a << '\n';
    }
    return 0;
}


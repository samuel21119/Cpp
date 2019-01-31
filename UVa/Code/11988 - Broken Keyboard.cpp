/*************************************************************************
  > File Name: 11988 - Broken Keyboard.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Dec 31 14:11:52 2017
*************************************************************************/

#include <iostream>
#include <list>
using namespace std;
char in[100003];
int main () {
    while (cin >> in) {
        list<char> l;
        auto it = l.begin();
        for (int i = 0; in[i] != '\0'; i++)  {
            if (in[i] == '[')
                it = l.begin();
            else if (in[i] == ']')
                it = l.end();
            else
                l.insert(it, in[i]);
        }
        for (it = l.begin(); it != l.end(); it++)
            cout << *it;
        cout << '\n';
    }
    return 0;
}

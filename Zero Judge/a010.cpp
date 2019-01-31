#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int input, _input, count;
    bool if_first_print, print, find;
    while (cin >> input) {
        count = 0;
        if_first_print = true;
        print = true;
        _input = input;
        find = false;
        for (int i = 2; input > 1 || print;) {
            if (i > sqrt(_input) && (!find)) {
                cout << _input;
                break;
            }
            if (input % i == 0) {
                count++;
                input /= i;
                print = find = true;
            }else {
                if (count > 0) {
                   if (if_first_print)
                      if_first_print = false;
                   else
                       cout << " * ";
                   cout << i;
                   if (count > 1)
                        cout << "^" << count;
                   print = false;
                }
                if (i == 2)
                    i++;
                else 
                    i += 2;
                count = 0;
            }
        }
        cout << endl;
    }
}

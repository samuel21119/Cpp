/*************************************************************************
  > File Name: 10815 - Andy's First Dictionary.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:24:01 2017
*************************************************************************/

#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int main() {
    set<string> input;
    string a;
    int i, j;
    char temp[205];
    string temp2;
    while (cin >> temp2) {
        i = 0;
        restart:
        j = 0;
        for (; i < (int)temp2.length(); i++) {
            if (temp2[i] >= 65 && temp2[i] <= 90) {
                temp[j++] = temp2[i] + 32;
            }else if (temp2[i] >= 97 && temp2[i] <= 122) {
                temp[j++] = temp2[i];
            }else {
                temp[j] = '\0';
                a = temp;
                input.insert(a);
                i++;
                goto restart;
            }
        }
        temp[j] = '\0';
        a = temp;
        input.insert(a);
    }
    for (set<string>::iterator first = input.begin(); first != input.end(); first++) {
        if (first == input.begin())
            first++;
        cout << *first << '\n';
    }
    return 0;
}


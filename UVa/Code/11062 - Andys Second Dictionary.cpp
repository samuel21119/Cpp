/*************************************************************************
  > File Name: 11062 - Andys Second Dictionary.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jan  3 10:09:16 2018
*************************************************************************/

#include <iostream>
#include <sstream>
#include <cstring>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<string> Set;
    string in, temp;
    bool con = false;
    while (getline(cin, in)) {
        for (int i = 0; i < (int)in.length(); i++)
            if (!isalpha(in[i]) && in[i] != '-') {
                in[i] = ' ';
            }
            else if (in[i] < 'a' && isalpha(in[i]))
                in[i] = (char)(in[i] + 'a' - 'A');
        stringstream ss(in);
        string tmp;
        int c = 0;
        while (ss >> tmp) {
            if (!c && con) {
                temp.erase(temp.end() - 1);
                tmp = temp + tmp;
            }
            if (tmp[tmp.length() - 1] == '-' && ss.peek() == EOF) {
                con = true;
                temp = tmp;
            }
            else {
                con = false;
                temp.clear();
                Set.insert(tmp);
            }
            c++;
        }
    }
    for (set<string>::iterator it = Set.begin(); it != Set.end(); it++)
        cout << *it << '\n';
    return 0;
}

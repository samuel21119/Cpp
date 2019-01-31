/*************************************************************************
  > File Name: 10018 - Reverse and Add.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan  1 20:34:49 2018
*************************************************************************/

#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
int _count;
void swap(string &str, int a, int b) {
    char t = str[a];
    str[a] = str[b];
    str[b] = t;
}
bool radd(long long &a) {
    _count++;
    stringstream ss;
    string s;
    ss << a;
    ss >> s; ss.str(""); ss.clear();
    int len = s.length();
    long long b;
    for (int i = 0;i < len / 2; i++)
        swap(s, i, len - i - 1);
    ss << s;
    ss >> b; ss.str(""); ss.clear();
    a += b;
    ss << a;
    ss >> s;
    len = s.length();
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - i - 1])
            return 0;
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        long long a;
        cin >> a;
        _count = 0;
        while (!radd(a));
        cout << _count << ' ' << a << '\n';
    }
    return 0;
}


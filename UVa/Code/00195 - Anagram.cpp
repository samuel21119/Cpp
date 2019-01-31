/*************************************************************************
  > File Name: 00195 - Anagram.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Oct  5 20:48:31 2018
*************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
bool compare(char a, char b){
    char la = tolower(a), lb = tolower(b);
    if (la == lb)
        return a < b;
    return la < lb;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        sort(s.begin(), s.end(), compare);
        do
            cout << s << '\n';
        while (next_permutation(s.begin(), s.end(), compare));
    }
    return 0;
}

/*************************************************************************
  > File Name: 10226 - Hardwood Species.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan 29 14:05:04 2018
*************************************************************************/

#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
using namespace std;

int main() {
    int c;
    cin >> c;
    
    cin.get();
    cin.get();
    while (c--) {
        int n = 0;
        map<string, int> m;
        char a[100];
        while (gets(a)) {
            if (a[0] == '\0')
                break;
            string str(a);
            m[str] += 1;
            n++;
        }
        for (auto it = m.begin(); it != m.end(); it++)
            printf("%s %.4f\n", it->first.c_str(), (float)((int)((it->second * 100.0 / n) * 10000 + 0.5)) / 10000);
        if (c) cout << '\n';
    }
    return 0;
}

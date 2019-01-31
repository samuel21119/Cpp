/*************************************************************************
  > File Name: 10364 - Square.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:56:24 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int sum, elong, n, l[21];
bool use[21];
bool cmp(int a, int b) {return a > b;}
bool dfs(int start, int esum, int edge) {
    if (edge == 3)
        return true;
    if (esum == elong)
        if (dfs(0, 0, edge + 1))
            return true;
    for (int i = start; i < n; i++) {
        if ((!use[i]) && l[i] + esum <= elong) {
            use[i] = true;
            if (dfs(i + 1, esum + l[i], edge))
                return true;
            use[i] = false;
        }
    }
    return false;
}
int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> l[i];
            sum += l[i];
        }
        if (sum % 4) {
            cout << "no\n";
            continue;
        }
        sort(l, l + n, cmp);
        if (sum / 4 < l[0]) {
            cout << "no\n";
            continue;
        }
        for (int i = 0; i < n; i++)
            use[i] = false;
        elong = sum / 4;
        if (dfs(0, 0, 0))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}


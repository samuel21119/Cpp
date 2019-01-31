/*************************************************************************
  > File Name: 12455 - Bars.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan 29 09:28:09 2018
*************************************************************************/

#include <iostream>
using namespace std;
int input[21];
int n, SUM;
int choosen[21];
bool dfs (int index, int choose, int sum) {
    if (sum > SUM)
        return 0;
    if (sum == SUM)
        return 1;
    if (index >= n)
        return 0;
    choosen[choose] = input[index];
    if (dfs(index + 1, choose + 1, sum + input[index]))
        return 1;
    if (dfs(index + 1, choose, sum))
        return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    while (c--) {
        cin >> SUM;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> input[i];
        if (dfs(0, 0, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

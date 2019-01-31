/*************************************************************************
  > File Name: 441 - Lotto.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:10:46 2017
*************************************************************************/

#include <iostream>
using namespace std;
int in[15], n;
int p[7];
void dfs(int index, int choose) {
    if (choose == 6) {
        for (int i = 0; i < 5; i++)
            cout << p[i] << ' ';
        cout << p[5] << '\n';
        return;
    }
    if (index == n)
        return;
    p[choose] = in[index];
    dfs(index + 1, choose + 1);
    dfs(index + 1, choose);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool a = false;
    while (cin >> n && n) {
        if (!a)
            a = true;
        else
            cout << '\n';
        for (int i = 0 ; i< n; i++)
            cin >> in[i];
        dfs(0, 0);
    }
    return 0;
}


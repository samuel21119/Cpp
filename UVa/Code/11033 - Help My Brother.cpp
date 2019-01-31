/*************************************************************************
  > File Name: 11033 - Help My Brother.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Apr  2 17:08:22 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int num[4][4];
int countN;
int n, m, p, Max;
string out[2];
void dfs(int index) {
    if (index == 7) {
        num[3][0] = n - num[0][0] - num[1][0] - num[2][0];
        num[0][3] = n - num[0][0] - num[0][1] - num[0][2];
        num[1][3] = n - num[1][0] - num[1][1] - num[1][2];
        num[2][1] = n - num[0][3] - num[1][2] - num[3][0];
        num[3][1] = n - num[0][1] - num[1][1] - num[2][1];
        int A = n - num[0][0] - num[1][1];
        int B = n - num[0][2] - num[1][2];
        int C = n - num[3][0] - num[3][1];
        num[3][3] = (A - B + C) >> 1;
        num[3][2] = (C - A + B) >> 1;
        num[2][3] = n - num[0][3] - num[1][3] - num[3][3];
        num[2][2] = n - num[0][2] - num[1][2] - num[3][2];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if ((num[i][j] < 1) || (num[i][j] > 7))
                    return;
        long long int mul = 1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                mul *= num[i][j];
        if (mul % m > p)
            return;
        char tmp[17];
        tmp[16] = '\0';
        int k = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp[k++] = num[i][j];
        string s(tmp);
        if (s < out[0]) {
            out[1] = out[0];
            out[0] = s;
        }
        else if (s < out[1])
            out[1] = s;
        countN++;
        return;
    }
    int x = index / 3;
    int y = index % 3;
    for (int i = 1; i <= 7; i++) {
        num[x][y] = i;
        dfs(index + 1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c = 1;
    while (cin >> n >> m >> p) {
        if (!n && !m && !p)
            break;
        cout << "Set " << c++ << ":\n";
        countN = 0;
        out[0] = out[1] = "9999999999999999";
        dfs(0);
        cout << countN << '\n';
        for (int i = 0; i < 2 && i < countN; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++)
                    cout << (int)out[i][j * 4 + k];
                cout << '\n';
            }
            cout << "....\n";
        }
    }
    return 0;
}

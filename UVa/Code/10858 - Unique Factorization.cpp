/*************************************************************************
  > File Name: 10858 - Unique Factorization.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Thu Jan  4 22:22:56 2018
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int di[50000], d, c;
vector<int> ans[10000];
int out[50000];

void dfs(int in, int index, int out_index) {
    if (in == 1) {
        ans[c].clear();
        for (int i = 0; i < out_index; i++)
            ans[c].push_back(out[i]);
        c++;
        return;
    }
    for (int i = index; i < d; i++) {
        if (in % di[i] == 0 && (in / di[i] >= di[i] || in == di[i])) {
            out[out_index] = di[i];
            dfs(in / di[i], i, out_index + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int in;
    while (cin >> in && in) {
        int sq = sqrt(in);
        d = 0;
        for (int i = 2; i <= sq; i++) {
            if (!(in % i)) {
                di[d++] = i;
                if (i * i != in)
                    di[d++] = in / i;
            }
        }
        sort(di, di + d);
        c = 0;
        if (d)
            dfs(in, 0, 0);
        cout << c << '\n';
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < (int)ans[i].size() - 1; j++)
                cout << ans[i][j] << ' ';
            cout << ans[i][ans[i].size() - 1] << '\n';
        }
    }
    return 0;
}

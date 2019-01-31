/*************************************************************************
  > File Name: 315 - Network.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:02:09 2017
*************************************************************************/

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int N, dfs_time, ans;
int _time[101], _low[101];
vector<int> link[101];
void dfs(int input, int parent) {
    int child = 0;
    int next, size;
    bool add = false;
    size = link[input].size();
    _time[input] = _low[input] = dfs_time++;
    for (int i = 0; i < size; i++) {
        next = link[input][i];
        if (!_time[next]) {
            child++;
            dfs(next, input);
            _low[input] = min(_low[input], _low[next]);
            if (_time[input] <= _low[next])
                add = true;
        }else if (next != parent)
            _low[input] = min(_low[input], _time[next]);
    }
    if ((child >= 2 || parent) && add)
        ans++;
}
int main() {
    string line;
    int a, b;
    while (scanf("%d ", &N) && N) {
        for (int i = 0; i <= N; i++) {
            _time[i] = _low[i] = 0;
            link[i].clear();
        }
        while (getline(cin, line)) {
            stringstream ss(line);
            ss >> a;
            if (!a)
                break;
            while (ss >> b) {
                link[a].push_back(b);
                link[b].push_back(a);
            }
        }
        dfs_time = 1;
        ans = 0;
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}


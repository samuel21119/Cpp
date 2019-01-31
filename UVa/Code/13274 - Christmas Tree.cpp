/*************************************************************************
  > File Name: 13274 - Christmas Tree.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:40:18 2017
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define IN in[index]
using namespace std;
int N, K;
vector<int> in[1005];
int dfs(int index, int p) {
    vector<int> sort_;
    int inc = IN.size() - 1, c = 1;
    if ((p &&inc < K) || (!p && inc + 1 < K))
        return 1;
    for (int i = 0; i <= inc; i++)
        if (IN[i] != p)  sort_.push_back(dfs(IN[i], index));
    sort(sort_.begin(), sort_.end());
    reverse(sort_.begin(), sort_.end());
    for (int i = 0; i < K; i++)    
        c += sort_[i];
    return c;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int case_, U, V;
    cin >> case_;
    for (int i = 1; i <= case_; i++) {
        cin >> N >> K;
        for (int j = 0; j < N - 1; j++) {
            cin >> U >> V;
            in[U].push_back(V);
            in[V].push_back(U);
        }
        cout << "Case " << i << ": " << dfs(1, 0) << '\n';
        for (int i = 0; i <= N; i++) {
            in[i].clear();
        }
    }
    return 0;
}


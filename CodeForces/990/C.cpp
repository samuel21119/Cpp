/*************************************************************************
  > File Name: C.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jun 10 19:07:38 2018
*************************************************************************/

#include <bits/stdc++.h>
#define l '('
#define r ')'
using namespace std;
stack<char> a;
vector<char> notOK[300001];
bool isregular[300001];
int OK, nOK, sum, nOKcnt;
int main() {
    int n;
    string s;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (auto c : s) {
            if (!a.empty() && a.top() == l && c == r){
                a.pop();
                continue;
            }
            a.push(c);
        }
        if (a.empty())
            isregular[i] = true, OK++;
        else {
            isregular[i] = false;
            while (!a.empty()) {
                notOK[nOK].push_back(a.top());
                a.pop();
            }
            nOK++;
        }
    }
    for (int i = 0; i < nOK; i++) {
        for (int j = 0; j < nOK; j++) {
            if (i == j)
                continue;
            if (notOK[i].size() != notOK[j].size())
                continue;
            int len = notOK[i].size();
            bool y = 1;
            if (notOK[i][0] == r || notOK[j][len - 1] == l) y = 0;
            for (int K = 1, L; K < len && y; K++) {
                L = len - K - 1;
                if (notOK[i][K] == notOK[j][L])
                    y = 0;
            }
            if (y)
                nOKcnt++;
        }
    }
    sum = OK * OK + nOKcnt;
    cout << sum << '\n';
    return 0;
}

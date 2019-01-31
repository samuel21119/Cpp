/*************************************************************************
  > File Name: 13153 - Number of Connected Components.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Jul 24 19:59:14 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
bool tmp[1000000];
int parent[1000000];
vector<int> p;
int usenum[1000000];
int n, cnt, size, num;

int find_parent(int i) {
    if (i == parent[i])
        return i;
    return parent[i] = find_parent(parent[i]);
}

void connect(int a, int b) {
    int pa = find_parent(a);
    int pb = find_parent(b);
    if (pa == pb)
        return;
    parent[pb] = pa;
}

void factorization(int i) {
    int first = 0;
    int a = 2;
    for (int j = 0; a <= sqrt(i); a = p[++j])
        if (!(i % a)) {
            if (!tmp[a]) {
                usenum[num++] = a;
                parent[a] = a;
            }
            tmp[a] = 1;
            if (!first)
                first = a;
            else {
                connect(first, a);
            }
            while (!(i % a)) 
                i /= a;
        }
    if (i > 1) {
        if (!tmp[i]) {
            usenum[num++] = i;
            parent[i] = i;
        }
        tmp[i] = 1;
        if (first)
            connect(first, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    tmp[2] = 1;
    p.push_back(2);
    for (int i = 3; i < 1000; i += 2) {
        if (tmp[i])
            continue;
        p.push_back(i);
        for (int j = i << 1; j < 1000; j += i)
            tmp[j] = 1;
    }
    p.push_back(1 << 30);
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        cin >> n;
        memset(tmp, 0, sizeof(tmp));
        num = cnt = 0;
        while (n--) {
            int i;
            cin >> i;
            if (i == 1)
                cnt++;
            else
                factorization(i);
        }
        for (int i = 0; i < num; i++) {
            int t;
            if (tmp[t = find_parent(usenum[i])])
                tmp[t] = 0, cnt++;
        }
        cout << "Case " << i << ": " << cnt << '\n';
    }
    return 0;
}

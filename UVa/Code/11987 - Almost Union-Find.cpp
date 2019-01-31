/*************************************************************************
  > File Name: 11987 - Almost Union-Find.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:34:35 2017
*************************************************************************/

#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int root[100002];
vector<int> element[100002];
int n, moves;
void swap(int &a, int &b) {
    int t;
    t = a;
    a = b;
    b = t;
}
void uni(int a, int b) {
    if (root[a] == root[b])
        return;
    int sa, sb, ra, rb;
    ra = root[a]; rb = root[b];
    sa = element[ra].size();
    sb = element[rb].size();
    if (sa < sb) {
        swap(ra, rb);
        swap(sa, sb);
    }
    for (int i = 0; i < sb; i++) {
        element[ra].pb(element[rb][i]);
        root[element[rb][i]] = ra;
    }
    element[rb].clear();
}

void move(int a, int b) {
    if (root[a] == root[b])
        return;
    int rb = root[b];
    vector<int>::iterator it = element[rb].begin();
    while(*it != b) it++;   
    root[b] = root[a];
    element[root[a]].pb(b);
    element[rb].erase(it);
}
void print(int a) {
    int ra = root[a], sum = 0;
    cout << element[ra].size() << ' ';
    for (int i = 0; i < (int)element[ra].size(); i++)
        sum += element[ra][i];
    cout << sum << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, k;
    while (cin >> n >> moves) {
        for (int i = 1; i <= n; i++) {
            element[i].clear();
            element[i].pb(i);
            root[i] = i;
        }
        while (moves--) {
            cin >> k;
            switch (k) {
                case 1:
                    cin >> a >> b;
                    uni(a, b);
                    break;
                case 2:
                    cin >> a >> b;
                    move(b, a); //b->a
                    break;
                default:
                    cin >> a;
                    print(a);
            }
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
map<pii, int> m;
pii add(pii a, pii b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}
int n, x, y;

pii coor[1010], clue[1010];
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coor[i] = {x, y};
    }
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        clue[i] = {x, y};
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[add(coor[i], clue[j])]++;
    for (auto i : m) {
        if (i.second == n) {
            cout << i.first.first << ' ' << i.first.second;
            return 0;
        }
    }
}

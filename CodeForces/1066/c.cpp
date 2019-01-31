#include<bits/stdc++.h>
using namespace std;

int q, l, r, i;
map<int,int> Map;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    l = 1, r = 0;
    cin >> q;
    while (q--) {
        cin >> s >> i;
        if (s == "R"){
            Map[i] = ++r;
        }else if( s == "L"){
            Map[i] = --l;
        }else
            cout << min(abs(Map[i] - l), abs(r-Map[i])) << '\n';
    }
    return 0;
}

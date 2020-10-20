/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Oct 14 20:34:55 2020
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        stringstream ss;
        multiset<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(i);
        while (s.size() > 1) {
            int a = *s.rbegin();
            s.erase(s.find(a));
            int b = *s.rbegin();
            s.erase(s.find(b));
            ss << a << ' ' << b << '\n';
            s.insert((a + b + 1) / 2);
        }
        cout << *s.begin() << '\n' << ss.str();
    }
    return 0;
}

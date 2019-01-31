/*************************************************************************
  > File Name: d.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Dec 18 22:09:49 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int in[200010];
struct node {
    int h, no;
    node(){}
    node(int a, int b) {
        h = a;
        no = b;
    }
    bool operator< (const node &b) const {
        if (h == b.h)
            return no > b.no;
        return h > b.h;
    }
};
vector<int> v;
set<int> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        v.emplace_back(in[i]);
        s.insert(i);
    }
    
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    priority_queue<node> pq;
    for (int i = 0; i < n; i++) {
        int t = lower_bound(v.begin(), v.end(), in[i]) - v.begin();
        pq.push({t, i});
    }
    int top = v.size() - 1;
    while (1) {
        if (pq.size() == 1) {
            if (pq.top().h == top)
                cout << "YES\n";
            else
                cout << "NO";
            return 0;
        }
        node a = pq.top();
        pq.pop();
        node b = pq.top();
        pq.pop();
        //cout << a.h << ' ' << b.h << '\n';
        auto it = s.find(a.no);
        if (a.h == b.h && ++it == s.find(b.no)) {
            if (a.h == top)
                break;
            s.erase(a.no);
            s.erase(b.no);
        }else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

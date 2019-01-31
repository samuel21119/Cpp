#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
string name[5] = {"Saki", "Megumin", "Rem", "Sagiri", "Kirino"};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        pair<int, int> score[5];
        for (int i = 0; i < 5; i++)
            score[i].first = 0, score[i].second = i;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                int a;
                cin >> a;
                if (a)
                    score[i].first++;
            }
        sort(score, score + 5);
        int m = score[4].first;
        vector<int> v;
        for (int i = 4; i >= 0; i--)
            if (score[i].first == m)
                v.eb(score[i].second);
        sort(v.begin(), v.end());
        cout << v.size() << '\n';
        for (int i : v)
            cout << name[i] << '\n';
    }
}
/*
0 0 1 1 0
1 0 0 0 1
0 1 0 1 0
0 1 0 0 1
1 0 1 0 0
*/

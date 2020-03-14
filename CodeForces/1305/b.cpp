#include <iostream>
#include <set>
#include <string>
using namespace std;

set<int> ans[1000];
int k;
int tmp[1010];
int main() {
    string s;
    cin >> s;
    int n = s.length();
    while (1) {
        bool find = 0;
        int l = 0;
        int r = s.length() - 1;
        while (l < r && s[l] == ')')
            l++;
        while (l < r && s[r] == '(')
            r--;
        if (l >= r)
            break;
        while (l < r) {
            ans[k].insert(l);
            ans[k].insert(r);
            tmp[l] = tmp[r] = k + 1;
            l++, r--;
            while (l < r && s[l] == ')')
                l++;
            while (l < r && s[r] == '(')
                r--;
        }
        string s2;
        for (int i = 0; i < s.length(); i++) {
            if (tmp[i] != k + 1)
                s2 += s[i];
        }
        s = s2;
        k++;
    }
    cout << k << '\n';
    for (int i = 0; i < k; i++) {
        cout << ans[i].size() << '\n';
        for (int j : ans[i])
            cout << j + 1 << ' ';
        cout << '\n';
    }
    return 0;
}

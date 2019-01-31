/*************************************************************************
  > File Name: 00102 - Ecological Bin Packing.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jan 27 10:35:37 2019
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string s, anss;
int in[3][3], ans, sum, tmp;
int convert[26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    convert['B' - 'A'] = 0;
    convert['C' - 'A'] = 2;
    convert['G' - 'A'] = 1;
    string s2;
    while (getline(cin, s2)) {
        if (s2[0] == '\0')
            break;
        ans = INT_MAX;
        s = "BCG";
        stringstream ss(s2);
        sum = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                ss >> in[i][j];
                sum += in[i][j];
            }
        do {
            tmp = sum;
            for (int i = 0; i < 3; i++)
                tmp -= in[i][convert[s[i] - 'A']];
            if (tmp < ans) {
                ans = tmp;
                anss = s;
            }
        }while (next_permutation(s.begin(), s.end()));
        cout << anss << ' ' << ans << '\n';
    }
    return 0;
}

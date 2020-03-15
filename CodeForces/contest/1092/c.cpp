/*************************************************************************
  > File Name: c.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Tue Dec 18 22:09:45 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
string ans;
pair<string, int> s[300];
int n;
int m1, m2;
bool m1_front = 1, m2_front = 1;
char out[300];
string ss1, ss2;
bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.first.length() < b.first.length();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    m1 = m2 = -1;
    for (int i = 0; i < n * 2 - 2; i++) {
        cin >> s[i].first;
        s[i].second = i;
        if (s[i].first.length() == n - 1) {
            m1 = m2;
            m2 = i;
        }
    }
    for (int i = 1; i < n - 1 && m1_front; i++) {
        m1_front &= s[m1].first[i] == s[m2].first[i - 1];
    }
    for (int i = 1; i < n - 1 && m1_front; i++) {
        m2_front &= s[m2].first[i] == s[m1].first[i - 1];
    }
    ss1 = s[m1].first;
    ss2 = s[m2].first;
    if (m1_front) {

        ans = ss1 + ss2.back();
    }
    else
        ans = ss2 + ss1.back();
    sort(s, s + n * 2 - 2, cmp);
    bool change = 0;
    for (int i = 0; i < n - 1; i++) {
        string s1 = s[i * 2].first;
        string s2 = s[i * 2 + 1].first;
        bool s1_front, s2_front, s1_back, s2_back;
        s1_front = s1_back = s2_front = s2_back = 1;
        for (int j = 0; j <= i; j++)
            s1_front &= s1[j] == ans[j];
        for (int j = 0; j <= i; j++)
            s2_front &= s2[j] == ans[j];
        int k = n - 1;
        for (int j = i; j >= 0; j--)
            s1_back &= s1[j] == ans[k--];
        k = n - 1;
        for (int j = i; j >= 0; j--)
            s2_back &= s2[j] == ans[k--];
        //cout << s1_front << s2_front << s1_back << s2_back << ' ' << s1 << ' ' << s2<< '\n';
        if (s1_front && s2_back) {
            out[s[i*2].second] = 'P';
            out[s[i*2+1].second] = 'S';
        }else if (s1_back && s2_front) {
            out[s[i*2].second] = 'S';
            out[s[i*2+1].second] = 'P';
        }else {
            change = 1;
            break;
        }
    }
    if (change && m1_front) {
        ans = ss2 + ss1.back();

        for (int i = 0; i < n - 1; i++) {
        string s1 = s[i * 2].first;
        string s2 = s[i * 2 + 1].first;
        bool s1_front, s2_front, s1_back, s2_back;
        s1_front = s1_back = s2_front = s2_back = 1;
        for (int j = 0; j <= i; j++)
            s1_front &= s1[j] == ans[j];
        for (int j = 0; j <= i; j++)
            s2_front &= s2[j] == ans[j];
        int k = n - 1;
        for (int j = i; j >= 0; j--)
            s1_back &= s1[j] == ans[k--];
        k = n - 1;
        for (int j = i; j >= 0; j--)
            s2_back &= s2[j] == ans[k--];
        if (s1_front && s2_back) {
            out[s[i*2].second] = 'P';
            out[s[i*2+1].second] = 'S';
        }else if (s1_back && s2_front) {
            out[s[i*2].second] = 'S';
            out[s[i*2+1].second] = 'P';
        }else {
            change = 1;
            break;
        }
    }
    }
    cout <<out<< '\n';
    return 0;
}

/*************************************************************************
  > File Name: A.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed May 30 16:57:34 2018
*************************************************************************/

#include <bits/stdc++.h>

using namespace std;

vector<string> a = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
vector<string> b = {"purple", "green", "blue", "orange", "red", "yellow"};

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.setf(ios::fixed), cout.precision(9);
  int n;
  cin >> n;
  map<string, string> mp;
  for (int i = 0; i < (int)a.size(); ++i) mp[b[i]] = a[i];
  for (int i = 0; i < n; ++i) {
    string now;
    cin >> now;
    mp.erase(now);
  }
  cout << mp.size() << '\n';
  for (auto& it : mp) cout << it.second << '\n';
}

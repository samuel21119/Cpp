/*************************************************************************
  > File Name: Hill Subsequences.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Fri Apr 27 20:08:34 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        vector<int> vec;
        int temp, n;
        while (ss >> temp)
            vec.push_back(temp);
        n = vec.size();
        int Increment[n + 1], Decreasing[n + 1];
        for (int i = 0; i <= n; i++)
            Increment[i] = Decreasing[i] = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (vec[i] < vec[j])
                    Increment[j] += Increment[i] + 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (vec[i] > vec[j])
                    Decreasing[j] += Increment[i] + Decreasing[i];
        int ans = 0;
        for (int i = 0; i < n; i++) ans += Decreasing[i];
        cout << ans << '\n';
    }
    return 0;
}

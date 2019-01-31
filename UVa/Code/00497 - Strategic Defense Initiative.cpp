/*************************************************************************
  > File Name: 497 - Strategic Defense Initiative.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Jan 24 21:22:16 2018
*************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;

int main() {
    int c;
    cin >> c;
    cin.get();
    cin.get();
    while (c--) {
        vector<int> input, pre, dp;
        int len;
        char a[50];
        while (gets(a)) {
            if (a[0] == '\0')break;
            int tmp = atoi(a);
            input.push_back(tmp);
            pre.push_back(-1);
            dp.push_back(1);
        }
        len = input.size();
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                if (input[i] < input[j] && dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                    pre[j] = i;
                }
        if (len) {
            int _max = 0;
            for (int i = 0; i < len; i++)
                if (dp[i] > dp[_max])
                    _max = i;
            cout << "Max hits: " << dp[_max] << '\n';
            int i = _max;
            stack<int> sta;
            while (i != -1) {
                sta.push(i);
                i = pre[i];
            }
            while (!sta.empty()) {
                cout << input[sta.top()] << '\n';
                sta.pop();
            }
        }
        else cout << "Max hits: 0\n";
        if (c)
            cout << '\n';
    }
    return 0;
}

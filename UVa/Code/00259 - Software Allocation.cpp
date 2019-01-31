/*************************************************************************
  > File Name: 00259 - Software Allocation.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jul 22 21:19:29 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int line[38][38];
int backtrace[38];
int trace(int target, int MIN) {
    if (!backtrace[target])
        return MIN;
    return trace(backtrace[target], min(MIN, line[backtrace[target]][target]));
}
void minus_trace(int target, int val) {
    line[target][backtrace[target]] += val;
    line[backtrace[target]][target] -= val;
    if (backtrace[target])
        minus_trace(backtrace[target], val);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    bool flag = 1;
    while (1) {
        flag = 0;
        int sum = 0;
        char out[11];
        for (int i = 1; i < 11; i++)
            out[i] = '_';
        memset(line, 0, sizeof(line));
        for (int i = 1; i <= 10; i++)
            line[0][i] = 1;
        while (getline(cin, s)) {
            flag = 1;
            if (s == "")
                break;
            int num = s[0] - 'A' + 11;
            for (int i = 3; s[i] != ';'; i++)
                line[s[i] - '0' + 1][num] = 1;
            sum += line[num][37] = s[1] - '0';
        }
        if (!flag)
            break;
        if (sum > 10) {
            cout << "!\n";
            continue;
        }
        for (bool flag = 1;;) {
            flag = 0;
            queue<int> q;
            q.push(0);
            memset(backtrace, -1, sizeof(backtrace));
            backtrace[0] = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (cur == 37) {
                    flag = 1;
                    break;
                }
                for (int i = 1; i <= 37; i++)
                    if (line[cur][i] > 0 && backtrace[i] == -1) {
                        q.push(i);
                        backtrace[i] = cur;
                    }
            }
            if (!flag)
                break;
            int MIN = trace(37, 1 << 30);
            minus_trace(37, MIN);
            sum -= MIN;
        }
        if (sum > 0)
            cout << "!";
        else
            for (int i = 1; i <= 10; i++) {
                bool p = true;
                for (int j = 11; j < 37; j++)
                    if (line[j][i] == 1) {
                        cout << (char)(j - 11 + 'A');
                        p = false;
                        break;
                    }
                if (p)
                    cout << '_';
            }
        cout << '\n';
    }
    return 0;
}

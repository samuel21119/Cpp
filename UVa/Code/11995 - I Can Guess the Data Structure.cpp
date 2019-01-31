/*************************************************************************
  > File Name: 11995 - I Can Guess the Data Structure.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:35:49 2017
*************************************************************************/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
string print(int a) {
    return a == 0 ? "stack\n" : a == 1 ? "queue\n" : "priority queue\n";
}
int main() {
    int in, d, num, temp;
    bool yes[3];
    while (cin >> in) {
        stack<int> sta;
        queue<int> que;
        priority_queue<int> pque;
        yes[0] = yes[1] = yes[2] = true;
        while (in--) {
            cin >> d >> num;
            if (d == 1) {
                if (yes[0])
                    sta.push(num);
                if (yes[1])
                    que.push(num);
                if (yes[2])
                    pque.push(num);
            }else {
                if (yes[0]) {
                    if (sta.empty())
                        yes[0] = false;
                    else {
                        temp = sta.top();
                        if (sta.top() != num)
                            yes[0] = false;
                        else
                            sta.pop();
                    }
                }
                if (yes[1]) {
                    if (que.empty())
                        yes[1] = false;
                    else {
                        temp = que.front();
                        if (que.front() != num)
                            yes[1] = false;
                        else
                            que.pop();
                    }
                }
                if (yes[2]) {
                    if (pque.empty())
                        yes[2] = false;
                    else {
                        temp = pque.top();
                        if (pque.top() != num)
                            yes[2] = false;
                        else
                            pque.pop();
                    }
                }
            }
        }
        temp = 0;
        temp = yes[0] + yes[1] + yes[2];
        if (temp > 1)
            cout << "not sure\n";
        else if (temp == 0)
            cout << "impossible\n";
        else
            for (int i = 0; i < 3; i++)
                if (yes[i]) {
                    cout << print(i);
                    break;
                }
    }
    return 0;
}


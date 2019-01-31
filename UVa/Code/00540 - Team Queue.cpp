/*************************************************************************
  > File Name: 540 - Team Queue.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Jan 20 10:45:29 2018
*************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int BT[1000001];
queue<int> team[1001];
int main() {
    int teams, count = 1;
    while (cin >> teams && teams) {
        for (int i = 0; i < teams; i++) {
            while (!team[i].empty())
                team[i].pop();
            int c, t;
            cin >> c;
            while (c--) {
                cin >> t;
                BT[t] = i;
            }
        }
        queue<int> teamqueue;
        cout << "Scenario #" << count++ << '\n';
        string in;
        while (cin >> in) {
            if (in[0] == 'S')
                break;
            if (in[0] == 'E') {
                int in2;
                cin >> in2;
                if (team[BT[in2]].empty())
                    teamqueue.push(BT[in2]);
                team[BT[in2]].push(in2);
            }
            else {
                int front = teamqueue.front();
                cout << team[front].front() << '\n';
                team[front].pop();
                if (team[front].empty())
                    teamqueue.pop();
            }
        }
        cout << '\n';
    }
    return 0;
}

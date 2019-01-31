/*************************************************************************
  > File Name: 10017 - The Never Ending Towers of Hanoi.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:37:35 2017
*************************************************************************/

#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;
stack<int> sta[3];
int a, b, c;
void move(int A, int C) {
    sta[C].push(sta[A].top());
    sta[A].pop();
    int s;//print
    cout << '\n';
    for (char i = 'A'; i < 'D'; i++) {
        cout << i << "=>";
        if(!sta[i-'A'].empty())
            cout << "   ";
        else {
            cout << '\n';
            continue;
        }
        stack<int> out;
        s = sta[i-'A'].size();
        for (int j = 0; j < s; j++) {
            out.push(sta[i-'A'].top());
            sta[i-'A'].pop();
        }
        for (int j = 0; j < s; j++) {
            cout << out.top();
            if (j != s-1)
                cout << ' ';
            else
                cout << '\n';
            sta[i-'A'].push(out.top());
            out.pop();
        }
    }
}
bool hanoi(int index, int A, int B, int C) { // A:start B:tmp C:end
    if (index == 1) {
        move(A, C);
        if (++c > b)
            return 1;
    }
    else {
        if (hanoi(index - 1, A, C, B))
            return 1;
        move(A, C);
        if (++c > b)
            return 1;
        if (hanoi(index - 1, B, A, C))
            return 1;
    }
    return 0;
}
int main() {
    int _c = 1;
    while (cin >> a >> b) {
        if (!a && !b)
            break;
        while (sta[0].size()) sta[0].pop();
        while (sta[1].size()) sta[1].pop();
        while (sta[2].size()) sta[2].pop();
        if (_c != 1)
            cout << '\n';
        cout << "Problem #" << _c++ << "\n\n";
        cout << "A=>   ";
        for (int i = a; i > 0; i--) {
            sta[0].push(i);
            cout << i << (i > 1 ? ' ' : '\n');
        }
        c = 1;
        cout << "B=>\nC=>\n";
        if (!b)
            continue;
        hanoi(a, 0, 1, 2);
    }
    cout << '\n';
    return 0;
}

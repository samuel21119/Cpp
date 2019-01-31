/*************************************************************************
  > File Name: 00101 - The Blocks Problem.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sun Jul  8 00:09:53 2018
*************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int position[25];
void init(stack<int> *sta, int i) {
    int p = position[i];
    for (int top = sta[p].top(); top != i; top = sta[p].top()) {
        sta[p].pop();
        sta[position[top] = top].push(top); 
    }
}
void move_onto(stack<int> *sta, int a, int b) {
    if (position[a] == position[b])
        return;
    init(sta, a);
    init(sta, b);
    sta[position[a]].pop();
    sta[position[b]].push(a);
    position[a] = position[b];
}
void move_over(stack<int> *sta, int a, int b) {
    if (position[a] == position[b])
        return;
    init(sta, a);
    sta[position[a]].pop();
    sta[position[b]].push(a);
    position[a] = position[b];
}
void pile_onto(stack<int> *sta, int a, int b) {
    if (position[a] == position[b])
        return;
    init(sta, b);
    stack<int> tmp;
    int pa = position[a];
    int pb = position[b];
    for (int top = sta[pa].top(); top != a; top = sta[pa].top()) {
        tmp.push(top);
        position[top] = pb;
        sta[pa].pop();
    }
    tmp.push(a);
    position[a] = pb;
    sta[pa].pop();
    while (!tmp.empty()) {
        sta[pb].push(tmp.top());
        tmp.pop();
    }
}
void pile_over(stack<int> *sta, int a, int b) {
    if (position[a] == position[b])
        return;
    stack<int> tmp;
    int pa = position[a];
    int pb = position[b];
    for (int top = sta[pa].top(); top != a; top = sta[pa].top()) {
        tmp.push(top);
        position[top] = pb;
        sta[pa].pop();
    }
    tmp.push(a);
    position[a] = pb;
    sta[pa].pop();
    while (!tmp.empty()) {
        sta[pb].push(tmp.top());
        tmp.pop();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2, move("move"), onto("onto"), quit("quit");
    int n, a, b;
    while (cin >> n) {
        stack<int> sta[n];
        for (int i = 0; i < n; i++) {
            sta[i].push(i);
            position[i] = i;
        }
        while (cin >> s1) {
            if (s1 == quit)
                break;
            cin >> a >> s2 >> b;
            if (s1 == move) {
                if (s2 == onto)
                    move_onto(sta, a, b);
                else
                    move_over(sta, a, b);
            }else {
                if (s2 == onto)
                    pile_onto(sta, a, b);
                else
                    pile_over(sta, a, b);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << i << ':';
            stack<int> tmp;
            while (!sta[i].empty()) {
                tmp.push(sta[i].top());
                sta[i].pop();
            }
            while (!tmp.empty()) {
                cout << ' ' << tmp.top();
                tmp.pop();
            }
            cout << '\n';
        }
    }
    return 0;
}

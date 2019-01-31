/*************************************************************************
  > File Name: 13257 - License Plates.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:39:25 2017
*************************************************************************/

#include <iostream>
#include <cstring>
#define endl '\n'
#define MAX 17576 //26*26*26
using namespace std;
char sub[3][MAX+1];
char in[100005];
bool use[26];
int length, _next[100005][26];
int ifhave(int sub1, int sub2, int index) {
    if (sub1 == 2){
        return 1;
    }
    if (_next[index][sub[sub1 + 1][sub2] - 'A'] > -1)
        return ifhave(sub1 + 1, sub2,  _next[index][sub[sub1 + 1][sub2] - 'A']);
    return 0;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int count, loop, length;
    count = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++) {
                sub[0][count] = (char)(i + 'A');
                sub[1][count] = (char)(j + 'A');
                sub[2][count++] = (char)(k + 'A');
            }
    cin >> loop;
    while(loop--) {
        cin >> in;
        length = strlen(in);
        for (int i = 0; i < 26; i++)
            _next[length][i] = -1;
        for (int i = length - 1; i >= 0; i--) {
            for (int c = 0; c < 26; c++)
                _next[i][c] = _next[i + 1][c];
            _next[i][in[i] - 'A'] = i + 1;
        }
        count = 0;
        for (int i = 0; i < MAX; i++) {
            count += ifhave(-1, i, 0);
        }
        cout << count << endl;
    }
    return 0;
}


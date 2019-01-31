/*************************************************************************
  > File Name: 11991 - Easy Problem from Rujia Lui.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:34:53 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int in[100002];
int s[100002];
int len, ask, num, t, front, last, mid;
bool cmp(int a, int b) {
    if (in[a] == in[b])
        return a < b;
    return in[a] < in[b];
}
int main() {
    while(cin >> len >> ask) {
        for (int i = 0; i < len; i++) {
            cin >> in[i];
        s[i] = i;
        }
        sort(s, s + len, cmp);
        for (int i = 0; i < ask; i++) {
            cin >> t >> num;
            front = 0; last = len;
            while (front < last) {
                mid = (front + last) / 2;
                if (in[s[mid]] >= num)
                    last = mid;
                else
                    front = mid + 1;
            }
            if (front + t - 1 >= len)
                cout << "0\n";
            else if (in[s[front + t - 1]] != num)
                cout << "0\n";
            else
                cout << s[front + t - 1] + 1 << '\n';
        }
    }
    return 0;
}


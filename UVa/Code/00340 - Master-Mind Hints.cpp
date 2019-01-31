/*************************************************************************
  > File Name: 00340 - Master-Mind Hints.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Jul 21 17:11:25 2018
*************************************************************************/

#include<bits/stdc++.h>
#define maxn 1010
using namespace std;
int main() {
    int n, count = 1;
    int a[maxn];
    int b[maxn];
    while (cin >> n && n) {
        cout << "Game " << count++ << ":" << endl;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        while (true) {
            int A = 0, B = 0;
            for (int i = 0; i < n; i++)
                cin >> b[i];
            if (b[0] == 0)
                break;
            for (int i = 0; i < n; i++)
                if (a[i] == b[i])
                    A++;
            for (int i = 1; i <= 9; i++) {
                int c1 = 0;
                int c2 = 0;
                for (int j = 0; j < n; j++) {
                    if(a[j] == i)
                        c1++;
                    if(b[j] == i)
                        c2++;
                }
                B += min(c1, c2);
            }
            cout << "    " << "(" << A << "," << B - A << ")" << endl;
        }
    }
    return 0;
}

/*************************************************************************
  > File Name: 10078 - The Art Gallery.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 18:49:51 2017
*************************************************************************/

#include <iostream>
using namespace std;
struct node{
    int x, y;
}n[55];
int c(node o, node a, node b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    bool flag;
    while (cin >> t && t) {
        flag = true;
        for (int i = 0; i < t; i++)
            cin >> n[i].x >> n[i].y;
        n[t] = n[0]; n[t + 1] = n[1];
        if (c(n[0], n[1], n[2]) >= 0) {
            for (int i = 0; i < t; i++)
                if (c(n[i], n[i + 1], n[i + 2]) < 0) {
                    flag = false;
                    break;
                }
        }else {
            for (int i = 0; i < t; i++)
                if (c(n[i], n[i + 1], n[i + 2]) > 0) {
                    flag = false;
                    break;
                }
        }
        if (flag)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}


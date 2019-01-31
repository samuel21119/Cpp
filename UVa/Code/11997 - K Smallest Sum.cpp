/*************************************************************************
  > File Name: 11997 - K Smallest Sum.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Sat Dec 30 19:36:12 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int l1[1000002];
int l2[1000002];
struct str {
    int sum, index;
    bool operator< (const str &b)const{
        return sum > b.sum;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    str a;
    while (cin >> k) {
        for (int i = 0; i < k; i++)
            cin >> l1[i];
        for (int c = 1; c < k; c++) {
            for (int i = 0; i < k; i++)
                cin >> l2[i];
            priority_queue<str> que;
            sort(l1, l1 + k);
            sort(l2, l2 + k);
            for (int i = 0; i < k; i++) {
                a.sum = l1[i] + l2[0];
                a.index = 0;
                que.push(a);
            }
            for (int i = 0; i < k; i++) {
                a = que.top();
                que.pop();
                l1[i] = a.sum;
                a.sum += l2[a.index + 1] - l2[a.index];
                a.index += 1;
                que.push(a);
            }
        }
        for (int i = 0; i < k - 1; i++)
            cout << l1[i] << " ";
        cout << l1[k - 1] << '\n';
   }
    return 0;
}


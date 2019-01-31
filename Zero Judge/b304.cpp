/*************************************************************************
  > File Name: b304.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Wed Mar  7 23:54:12 2018
*************************************************************************/

#include <iostream>
#include <stack>
using namespace std;
#define sl '('
#define ml '['
#define sr ')'
#define mr ']'
int main() {
    int c;
    char in, cur, eat[1000];
    cin >> c;
    getchar();
    while (c--) {
        stack<char> sta;
        bool flag = true;
        while (flag) {
            in = getchar();
            if (in == '\n')
                break;
            if (in == sl || in == ml)
                sta.push(in);
            else {
                if (sta.empty()) {
                    flag = false;
                    cin.getline(eat, 1000);
                    break;
                }
                cur = sta.top();
                sta.pop();
                if ((in == sr && cur == ml) || (in == mr && cur == sl)) {
                    flag = false;
                    cin.getline(eat, 1000);
                }
            }
        }
        if (!sta.empty())
            flag = 0;
        cout << (flag ? "Yes\n" : "No\n");
    }
}

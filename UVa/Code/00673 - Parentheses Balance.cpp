/*************************************************************************
  > File Name: 673 - Parentheses Balance.cpp
  > Author: Samuel
  > Mail: enminghuang21119@gmail.com
  > Created Time: Mon Jan 29 21:52:20 2018
*************************************************************************/

#include <cstdio>
#include <string>
#include <stack>
using namespace std;

int main() {
    int c;
    scanf("%d\n", &c);
    while (c--) {
        char in[130];
        fgets(in, 130, stdin);
        stack<char> s;
        bool flag = true;
        for (int i = 0; in[i] != '\0' && flag; i++) {
            if (in[i] == '[' || in[i] == '(')
                s.push(in[i]);
            else if (in[i] == ']' || in[i] == ')') {
                if (s.empty())
                    flag = false;
                else {
                    char t = s.top();
                    s.pop();
                    if ((t == '[' && in[i] != ']') || (t == '(' && in[i] != ')'))
                        flag = false;
                }
            }
        }
        if (!s.empty())
            flag = false;
        printf("%s", flag ? "Yes\n" : "No\n");
    }
    return 0;
}

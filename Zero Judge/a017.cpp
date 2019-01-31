#include <string>
#include <iostream>
using namespace std;
string input;
long long int result;
int Calc(int L, int R){
    int IfBrackets = 0;
    for (int i = R - 1; i >= L; i--) {
        if (input[i] == '(') IfBrackets++;
        if (input[i] == ')') IfBrackets--;
        if (input[i] == '+' && IfBrackets == 0) {
            return Calc(L, i) + Calc(i + 1, R);
        }
        if (input[i] == '-' && IfBrackets == 0) {
            return Calc(L, i) - Calc(i + 1, R);
        }
    }
    for (int i = R - 1; i >= L; i--) {
        if (input[i] == '(') IfBrackets++;
        if (input[i] == ')') IfBrackets--;
        if (input[i] == '*' && IfBrackets == 0) {
            return Calc(L, i) * Calc(i + 1, R);
        }
        if (input[i] == '/' && IfBrackets == 0) {
            return Calc(L, i) / Calc(i + 1, R);
        }
        if (input[i] == '%' && IfBrackets == 0) {
            return Calc(L, i) % Calc(i + 1, R);
        }
    }
    if (input[L] == '(' && input[R - 1] && ')') return Calc(L + 1, R - 1);
    if (input[L] == ' ' && input[R - 1] == ' ') return Calc(L + 1, R - 1);
    if (input[L] == ' ') return Calc(L + 1, R);
    if (input[R - 1] == ' ') return Calc(L, R - 1);
    int number = 0;
    for (int i = L; i < R; i++) {
        number = number * 10 + input[i] - '0';
    }
    return number;
}

int main(){
    while(getline(cin, input)) {
        result = Calc(0, input.length());
        cout << result << endl;
    }
}

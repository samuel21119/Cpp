#include <iostream>
#include <cstring>
using namespace std;
int abs(int in) {
    if (in >= 0) 
        return in;
    return -in;
}
int V(char in) {
    switch (in) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}
int main() {
    char in1[2000], in2[2000], out[2000], num;
    int in1_L, in2_L, int1, int2, minus;
    ios::sync_with_stdio(0);
    while (cin >> in1) {
        if (in1[0] == '#')
            break;
        cin >> in2;
        in1_L = strlen(in1);
        in2_L = strlen(in2);
        int1 = int2 = 0;
        int pre = in1_L - 1;
        for (int i = in1_L - 1; i >= 0; i--) {
            if (V(in1[i]) >= V(in1[pre])) {
                pre = i;
                int1 += V(in1[i]);
            }else
                int1 -= V(in1[i]);
        }
        pre = in2_L - 1;
        for (int i = in2_L - 1; i >= 0; i--) {
            if (V(in2[i]) >= V(in2[pre])) {
                pre = i;
                int2 += V(in2[i]);
            }else
                int2 -= V(in2[i]);
        }
        int divide = 1000;
        minus = abs(int1 - int2);
        if (!minus) {
            cout << "ZERO\n";
        }
        else {
            while (divide > 0) {
                if (minus >= divide) {
                    int temp = minus / divide * divide;
                    minus %= divide;
                    if (temp >= 1000) {
                        for (; temp > 0; temp -= 1000)
                            cout << "M";
                    }
                    else if (temp == 900)
                        cout << "CM";
                    else if (temp >= 100) {
                        if (temp >= 500) {
                            cout << "D";
                            temp -= 500;
                        }
                        if (temp == 400) {
                            cout << "CD";
                            temp = 0;
                        }
                        for (; temp > 0; temp -= 100) {
                            cout << "C";
                        }
                    }
                    else if (temp == 90)
                        cout << "XC";
                    else if (temp >= 10) {
                        if (temp >= 50) {
                            cout << "L";
                            temp -= 50;
                        }
                        if (temp == 40) {
                            cout << "XL";
                            temp = 0;
                        }
                        for (; temp > 0; temp -= 10)
                            cout << "X";
                    }
                    else if (temp == 9) 
                        cout << "IX";
                    else {
                        if (temp >= 5) {
                             cout << "V";
                             temp -= 5;
                        }
                        if (temp == 4) {
                            cout << "IV";
                            break;
                        }
                        for (; temp > 0; temp--) {
                            cout << "I";
                        }
                    }
                }else {
                    divide /= 10;
                }
            }
            cout << '\n';
        }
    }
}

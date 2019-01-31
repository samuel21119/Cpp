#include "BigInteger2.h"
#include <cstdlib>
using namespace std;
Number Abs(Number input){
    if (input < 0) {
        input *= -1;
    }
    return input;
}
void mode1() {
    int count = 0;
    Number x, y, d, temp, temp2, temp3;
    cout << "請輸入x^2-2y^2=-d^2的d值:";
    cin >> d;
    x = 1;
    while(1) {
        // y = sqrt((x^2 + d^2 )/2)
        temp = x * x;
        temp += d * d;
        if (temp % 2 == 0) {
            y = temp / 2;
            y = sqrt(y);
            if (y != -1) {
                temp2 = x-d;
                temp2 /= 2;
                temp3 = x+d;
                temp3 /= 2;
                cout << "x:  " << x << " , y:  " << y << " , (x-d)/2: " << temp2 << " , (x+d)/2: " << temp3 << endl;
            }
        }
        x += 1;
    }
}
void mode2() {
    int count = 0;
    Number x, y, d, temp, temp2, temp3, temp4;
    cout << "請輸入x^2-3y^2=d^2的d值:";
    cin >> d;
    x = 1;
    while(1) {
        // y = sqrt((x^2 - d^2 )/3)
        temp = x * x;
        temp -= d * d;
        if (temp % 3 == 0) {
            y = temp / 3;
            y = sqrt(y);
            if (y != -1) {
                temp2 = x*2;
                temp3 = y*3;
                cout << "x: " << x << " , y: " << y << " , a=2x: " << temp2 << " , h=3y: " << temp3 << endl;
            }
        }
        x += 1;
    }
}
void mode3() {
    int count = 0;
    Number x, y, d, temp, temp2, temp3;
    cout << "請輸入x^2-10y^2=-d^2的d值:";
    cin >> d;
    x = 1;
    while(1) {
        // y = sqrt((x^2 + d^2 )/10)
        temp = x * x;
        temp += d * d;
        if (temp % 10 == 0) {
            y = temp / 10;
            y = sqrt(y);
            if (y != -1) {
                temp2 = x-d;
                temp2 /= 2;
                temp3 = x+d;
                temp3 /= 2;
                cout << "x: " << x << " , y: " << y << " , (x-d)/2: " << temp2 << " , (x+d)/2: " << temp3 << endl;
            }
        }
        x += 1;
    }
}
void mode4() {
    Number M, N;
    cout << "請輸入m的值: ";
    cin >> M;
    cout << "請輸入n的值: ";
    cin >> N;
    cout << "m: " << M << " ,n: " << N << " ,a: " << M * M + N * N << " ,b: " << Abs(N * N + M*N*4 - M*M)
    << " ,c: " << Abs(M*M + M*N - N*N) << endl;
}
void mode5(){
    Number a, b, y;
    cout << "請輸入α的值: " ;
    cin >> a;
    cout << "請輸入β的值: " ;
    cin >> b;
    cout << "請輸入γ的值: " ;
    cin >> y;
    cout << "a: " << y << " ,b: " << a*2 + b << " ,c: " << b*2 - a << endl;
}
int main(){
    int input;
    Number Max;
    cout << "請輸入模式(1~5):\n1: x^2 -2y^2 = -d^2\n2: x^2 -3y^2 = d^2\n3: x^2 -10y^2 = -d^2"
    << "\n4: a = m^2 + n^2 ...\n5: a = γ...\n" ;
    cin >> input;
    switch (input) {
        case 1:
            mode1();
            break;
        case 2:
            mode2();
            break;
        case 3:
            mode3();
            break;
        case 4:
            mode4();
            break;
        case 5:
            mode5();
            break;
        default:
            break;
    }
}

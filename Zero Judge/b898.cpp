#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int length(char input[]) {
    int i = 0;
    while(input[i] != '.') {
        i++;
    }
    return i;
}
int bigger(char input1[], char input2[], int length1, int length2) {
    if (length1 > length2) {
        return 1;
    }else if (length1 < length2) {
        return 0;
    }
    for (int i = 0; i <= length1; i++) {
        if (input1[i] > input2[i]) {
            return 1;
        }else if (input1[i] < input2[i]) {
            return 0;
        }
    }
    return 1;
}
int main(){
    char a[100003], b[100003], c[100003];
    int aL, bL, cL;
    int d;
    cin >> d;
    for (int i = 0; i < 5; i++) {
        memset (a, '.', 100003);
        memset (b, '.', 100003);
        memset (c, '.', 100003);
        cin >> a >> b >> c;
        aL = length(a);
        bL = length(b);
        cL = length(c);
        if (bigger(a, b, aL, bL) && bigger(a, c, aL, cL)) {
            cout << a << endl;
        }else if (bigger(b, a, bL, aL) && bigger(b, c, bL, cL)) {
            cout << b << endl;
        }else if (bigger(c, a, cL, aL) && bigger(c, b, cL, bL)) {
            cout << c << endl;
        }
    }
}

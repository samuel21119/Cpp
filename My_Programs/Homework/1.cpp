#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int array1[10001];//2
int array2[10001];//8
int array3[10001];//10
int length(int a[]) {
    int b = 0;
    while (a[b] != -1)
        b++;
    return b;
}
void check(int input2, int nary, int array0[]) {
    if (array0[input2] >= nary) {
        if (array0[input2 + 1] == -1) {
            array0[input2 + 1] = 1;
        }
        else {
            array0[input2 + 1] += 1;
        }
        array0[input2] = 0;
        check(input2 + 1, nary, array0);
    }
}

bool checkIfOk(int array0[]) {
    int length1 = length(array0);
    for (int i = 0; i <= length1 / 2; i++) {
        if (array0[i] != array0[length1 - i - 1])
        return false;
    }
    return true;
}
int main() {
    int count = 1;
    for(int i = 0; i < 10001; i++) {
        array1[i] = array2[i] = array3[i] = -1;
    }
    array1[0] = array2[0] = array3[0] = 0;
    while (array1[10000] == -1) {
        if (checkIfOk(array1) && checkIfOk(array2) && checkIfOk(array3)) {
            cout << count++ << ":  \n\tDec: ";
            for (int i = 0; i < length(array3); i++) {
                cout << array3[i];
            }
            cout << "\n\tOct: ";
            for (int i = 0; i < length(array2); i++) {
                cout << array2[i];
            }
            cout << "\n\tBin: ";
            for (int i = 0; i < length(array1); i++) {
                cout << array1[i];
            }
            cout << "\n";
        }
        array1[0] += 1;
        array2[0] += 1;
        array3[0] += 1;
        check(0, 10, array3);
        check(0, 8, array2);
        check(0, 2, array1);
    }
}

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
char a[501], b[501], c[501];
int l1, l2, l3;
char oper;
void Add() {
    l1 = strlen(a);
    l2 = strlen(b);
    l3 = max(l1, l2);
    for (int i = 0; i < l3; i++) {
        if (i < l1) {
            c[i] += a[i];
        }
        if (i < l2) {
            c[i] += b[i];
        }
        if (c[i] > 9) {
            c[i + 1] = c[i] / 10;
            c[i] %= 10;
        }
    }
}
int main() {
    while (cin >> a >> oper >> b) {
        for (int i = 0; i < 501; i++) {
            c[i] = 0;
        }
        l3 = 0;
        switch (oper) {
            case '+':
                Add();
        }
    }
}


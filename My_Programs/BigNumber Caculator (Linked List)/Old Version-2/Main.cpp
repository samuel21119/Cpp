#include "BigNumberCalculator3.h"
#include <time.h>
#include <fstream>
#include <string.h>
using namespace std;
Number Fac(Number a){
    if(a > 1){
        return a * Fac(a - 1);
    }
    return a;
}
int main(){
    ofstream output;
    char TXT[12];
    Number a,b;
    int length;
    clock_t t;
    while(1){
        cin >> a;
        sprintf(TXT, "%d", NumberToInt(a));
        strcat(TXT,"!");
        output.open(TXT);
        b = 1;
        t = clock();
        output << a << "!\n";
        for(; a > 1; a--){
            b *= a;
        }
        t = clock() - t;
        length =  b.Length() + 1;
        output << b << endl << "Length: " << length << endl << "Elapsed time: "
        << ((float)t)/CLOCKS_PER_SEC << " seconds";
        cout << b << endl << "Length: " << length << endl << "Elapsed time: "
        << ((float)t)/CLOCKS_PER_SEC << " seconds" << endl;

    }
}

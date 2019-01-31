#include "BigNumberCalculator2.h"
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;
int main(){
    Number a,b;
    clock_t t;
    ofstream file;
    file.open("result.txt");
    a = 1;
    while(a <= 1000){
        t = clock();
        b = fac(a);
        t = clock() - t;
        file << a << endl << b << endl << "Length: " << b.Length() + 1 << endl << "Time used: "
        << ((float)t)/CLOCKS_PER_SEC << " seconds" << endl;
        a++;
    }
    file.close();
}

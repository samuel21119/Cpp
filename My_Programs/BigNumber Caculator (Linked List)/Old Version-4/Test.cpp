#include <iostream>
#include <cstdlib>
#include "BigNumber.h"
int main(){
    BigNumber A;
    A.Scan();
    A.Calc();
    A.Print();
    A.Free();
    return 0;
}
